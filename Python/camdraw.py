import cv2
import mediapipe as mp
import numpy as np

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7)
mp_draw = mp.solutions.drawing_utils

cap = cv2.VideoCapture(0)
ret, frame = cap.read()
canvas = np.zeros_like(frame)          # layer gambar terpisah

prev_x, prev_y = None, None
draw_color = (0, 255, 0)               # hijau default
brush_size = 5
mode = "draw"                          # "draw" | "erase"

# Pallet warna (B, G, R)
colors = {
    "g": (0, 255, 0),   # hijau
    "r": (0, 0, 255),   # merah
    "b": (255, 100, 0), # biru
    "w": (255, 255, 255),
}

print("="*45)
print("  FINGER DRAW — Layout")
print("="*45)
print("  TELUNJUK    → gambar")
print("  Pose peace  → stop")
print()
print("  Keyboard:")
print("  g/r/b/w → ganti warna (hijau/merah/biru/putih)")
print("  e       → eraser")
print("  d       → brush")
print("  c       → clear)
print("  +/-     → ukuran brush")
print("  q / ESC → keluar")
print("="*45)


def count_fingers_up(hand_landmarks):
    """Hitung jari yang terangkat (selain ibu jari)."""
    tips = [8, 12, 16, 20]   # ujung telunjuk, tengah, manis, kelingking
    pip  = [6, 10, 14, 18]   # sendi kedua
    count = sum(
        1 for t, p in zip(tips, pip)
        if hand_landmarks.landmark[t].y < hand_landmarks.landmark[p].y
    )
    return count


while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)         # mirror cam
    h, w, _ = frame.shape
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb)

    finger_x, finger_y = None, None

    if result.multi_hand_landmarks:
        for hlm in result.multi_hand_landmarks:
            mp_draw.draw_landmarks(frame, hlm, mp_hands.HAND_CONNECTIONS)

            n_fingers = count_fingers_up(hlm)
            tip = hlm.landmark[8]          # ujung telunjuk
            cx = int(tip.x * w)
            cy = int(tip.y * h)

            if n_fingers == 1:             # hanya telunjuk → brush/eraser
                finger_x, finger_y = cx, cy
                if prev_x and prev_y:
                    color = (0, 0, 0) if mode == "erase" else draw_color
                    size  = brush_size * 5 if mode == "erase" else brush_size
                    cv2.line(canvas, (prev_x, prev_y), (cx, cy), color, size)
                cv2.circle(frame, (cx, cy), brush_size, draw_color, -1)
            else:
                # 2+ jari = angkat pena
                prev_x, prev_y = None, None

        prev_x, prev_y = finger_x, finger_y

    # Gabungkan canvas ke frame
    canvas_gray = cv2.cvtColor(canvas, cv2.COLOR_BGR2GRAY)
    _, mask = cv2.threshold(canvas_gray, 10, 255, cv2.THRESH_BINARY)
    mask_inv = cv2.bitwise_not(mask)
    bg = cv2.bitwise_and(frame, frame, mask=mask_inv)
    fg = cv2.bitwise_and(canvas, canvas, mask=mask)
    combined = cv2.add(bg, fg)

    # ── UI overlay ──────────────────────────────────────────────────────────
    label = f"Mode: {'HAPUS' if mode == 'erase' else 'GAMBAR'}  Brush: {brush_size}"
    cv2.putText(combined, label, (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (200, 200, 200), 2)

    # Indikator warna aktif
    cv2.rectangle(combined, (w-50, 10), (w-10, 50), draw_color, -1)
    cv2.rectangle(combined, (w-50, 10), (w-10, 50), (255,255,255), 1)

    cv2.imshow("Finger Draw", combined)

    # ── Keyboard ────────────────────────────────────────────────────────────
    key = cv2.waitKey(1) & 0xFF
    if key in (ord('q'), 27):          # q atau ESC
        break
    elif key == ord('c'):
        canvas = np.zeros_like(frame)
    elif key == ord('e'):
        mode = "erase"
    elif key == ord('d'):
        mode = "draw"
    elif key in [ord(k) for k in colors]:
        draw_color = colors[chr(key)]
        mode = "draw"
    elif key == ord('+'):
        brush_size = min(brush_size + 2, 30)
    elif key == ord('-'):
        brush_size = max(brush_size - 2, 2)

cap.release()
cv2.destroyAllWindows()

