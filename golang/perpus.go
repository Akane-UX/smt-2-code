package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Buku struct {
	ID        int
	Judul     string
	Penulis   string
	Stok      int
	Dipinjam  int
}

type Perpustakaan struct {
	buku   []Buku
	lastID int
}

func (p *Perpustakaan) TambahBuku(judul, penulis string, stok int) {
	p.lastID++
	p.buku = append(p.buku, Buku{
		ID:      p.lastID,
		Judul:   judul,
		Penulis: penulis,
		Stok:    stok,
	})
	fmt.Printf("✅ Buku '%s' berhasil ditambah!\n", judul)
}

func (p *Perpustakaan) LihatSemuaBuku() {
	if len(p.buku) == 0 {
		fmt.Println("📭 Perpustakaan kosong, bro.")
		return
	}
	fmt.Println("\n╔══════════════════════════════════════════════════════╗")
	fmt.Printf("║ %-4s %-25s %-15s %-5s %-8s ║\n", "ID", "Judul", "Penulis", "Stok", "Dipinjam")
	fmt.Println("╠══════════════════════════════════════════════════════╣")
	for _, b := range p.buku {
		fmt.Printf("║ %-4d %-25s %-15s %-5d %-8d ║\n",
			b.ID, b.Judul, b.Penulis, b.Stok, b.Dipinjam)
	}
	fmt.Println("╚══════════════════════════════════════════════════════╝")
}

func (p *Perpustakaan) CariBuku(keyword string) {
	keyword = strings.ToLower(keyword)
	found := false
	for _, b := range p.buku {
		if strings.Contains(strings.ToLower(b.Judul), keyword) ||
			strings.Contains(strings.ToLower(b.Penulis), keyword) {
			fmt.Printf("📖 [%d] %s — %s | Stok: %d | Dipinjam: %d\n",
				b.ID, b.Judul, b.Penulis, b.Stok, b.Dipinjam)
			found = true
		}
	}
	if !found {
		fmt.Println("❌ Gak ketemu, coba cari yang lain.")
	}
}

func (p *Perpustakaan) PinjamBuku(id int) {
	for i, b := range p.buku {
		if b.ID == id {
			if b.Stok-b.Dipinjam <= 0 {
				fmt.Println("😬 Stoknya habis, sabar dulu.")
				return
			}
			p.buku[i].Dipinjam++
			fmt.Printf("✅ Berhasil pinjam '%s'!\n", b.Judul)
			return
		}
	}
	fmt.Println("❌ ID buku gak ada.")
}

func (p *Perpustakaan) KembalikanBuku(id int) {
	for i, b := range p.buku {
		if b.ID == id {
			if b.Dipinjam == 0 {
				fmt.Println("🤨 Gak ada yang lagi minjem buku ini.")
				return
			}
			p.buku[i].Dipinjam--
			fmt.Printf("✅ Buku '%s' berhasil dikembalikan!\n", b.Judul)
			return
		}
	}
	fmt.Println("❌ ID buku gak ada.")
}

func (p *Perpustakaan) HapusBuku(id int) {
	for i, b := range p.buku {
		if b.ID == id {
			p.buku = append(p.buku[:i], p.buku[i+1:]...)
			fmt.Printf("🗑️ Buku '%s' dihapus.\n", b.Judul)
			return
		}
	}
	fmt.Println("❌ ID buku gak ada.")
}

// ── Helper input ──────────────────────────────────────────

var scanner = bufio.NewScanner(os.Stdin)

func input(prompt string) string {
	fmt.Print(prompt)
	scanner.Scan()
	return strings.TrimSpace(scanner.Text())
}

func inputInt(prompt string) int {
	for {
		raw := input(prompt)
		n, err := strconv.Atoi(raw)
		if err == nil {
			return n
		}
		fmt.Println("⚠️  Input angka dong!")
	}
}

// ── Main ──────────────────────────────────────────────────

func main() {
	p := &Perpustakaan{}

	// Seed data biar gak kosong-kosong amat
	p.TambahBuku("Clean Code", "Robert C. Martin", 3)
	p.TambahBuku("The Go Programming Language", "Donovan & Kernighan", 2)
	p.TambahBuku("Atomic Habits", "James Clear", 5)

	for {
		fmt.Println("\n═══════ SISTEM PERPUSTAKAAN ═══════")
		fmt.Println("1. Lihat semua buku")
		fmt.Println("2. Tambah buku")
		fmt.Println("3. Cari buku")
		fmt.Println("4. Pinjam buku")
		fmt.Println("5. Kembalikan buku")
		fmt.Println("6. Hapus buku")
		fmt.Println("0. Keluar")
		fmt.Println("═══════════════════════════════════")

		pilihan := inputInt("Pilih menu: ")

		switch pilihan {
		case 1:
			p.LihatSemuaBuku()

		case 2:
			judul := input("Judul buku: ")
			penulis := input("Penulis: ")
			stok := inputInt("Stok: ")
			p.TambahBuku(judul, penulis, stok)

		case 3:
			keyword := input("Cari (judul/penulis): ")
			p.CariBuku(keyword)

		case 4:
			p.LihatSemuaBuku()
			id := inputInt("ID buku yang dipinjam: ")
			p.PinjamBuku(id)

		case 5:
			p.LihatSemuaBuku()
			id := inputInt("ID buku yang dikembalikan: ")
			p.KembalikanBuku(id)

		case 6:
			p.LihatSemuaBuku()
			id := inputInt("ID buku yang dihapus: ")
			p.HapusBuku(id)

		case 0:
			fmt.Println("👋 Bye!")
			return

		default:
			fmt.Println("⚠️  Menu gak valid, coba lagi.")
		}
	}
}