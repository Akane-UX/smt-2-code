-- Gunakan atau buat database
CREATE DATABASE toko_serba_ada;
USE toko_serba_ada;


-- Tabel produk
CREATE TABLE produk (
    id_produk INT PRIMARY KEY,
    nama_produk VARCHAR(100),
    kategori VARCHAR(50),
    harga DECIMAL(10,2)
);

INSERT INTO produk VALUES
(1, 'Laptop Lenovo', 'Elektronik', 8500000.00),
(2, 'Kaos Polos', 'Pakaian', 75000.00),
(3, 'Kulkas Samsung', 'Elektronik', 3200000.00),
(4, 'Celana Jeans', 'Pakaian', 120000.00),
(5, 'Kompor Gas', 'Peralatan Dapur', 275000.00),
(6, 'TV LED', 'Elektronik', 2100000.00),
(7, 'Jaket Hoodie', 'Pakaian', 185000.00),
(8, 'Blender Philips', 'Peralatan Dapur', 480000.00),
(9, 'Kipas Angin', 'Elektronik', 300000.00);

-- Tabel pelanggan
CREATE TABLE pelanggan (
    id_pelanggan INT PRIMARY KEY,
    nama VARCHAR(100),
    email VARCHAR(100),
    kota VARCHAR(50)
);

INSERT INTO pelanggan VALUES
(101, 'Andi Saputra', 'andi@gmail.com', 'Jakarta'),
(102, 'Bella Sari', 'bella@yahoo.com', 'Bandung'),
(103, 'Citra Dewi', 'citra@ymail.com', 'Surabaya'),
(104, 'Doni Hidayat', 'doni@tokomail.com', 'Jakarta'),
(105, 'Eka Prasetya', 'eka@gmail.com', 'Yogyakarta');

-- Tabel transaksi
CREATE TABLE transaksi (
    id_transaksi INT PRIMARY KEY,
    id_pelanggan INT,
    id_produk INT,
    jumlah INT,
    total_bayar DECIMAL(10,2),
    tanggal DATE
);

INSERT INTO transaksi VALUES
(201, 101, 1, 1, 8500000.00, '2024-01-15'),
(202, 101, 2, 3, 225000.00, '2024-02-02'),
(203, 102, 4, 2, 240000.00, '2024-02-12'),
(204, 103, 5, 1, 275000.00, '2024-03-01'),
(205, 104, 3, 1, 3200000.00, '2024-03-21'),
(206, 104, 7, 2, 370000.00, '2024-04-02');

-- Tabel supplier
CREATE TABLE supplier (
    id_supplier INT PRIMARY KEY,
    nama VARCHAR(100),
    kota VARCHAR(50)
);

INSERT INTO supplier VALUES
(301, 'CV Sumber Makmur', 'Jakarta'),
(302, 'PT Elektronik Jaya', 'Bandung'),
(303, 'Toko Pakaian Modern', 'Surabaya'),
(304, 'PT Peralatan Rumah', 'Yogyakarta');

-- 1. Hitung total jumlah data produk
SELECT COUNT(*) AS total_produk FROM produk;
 
-- 2. Total seluruh nilai harga dari tabel produk
SELECT SUM(harga) AS total_harga FROM produk;
 
-- 3. Harga rata-rata semua produk
SELECT AVG(harga) AS rata_rata_harga FROM produk;
 
-- 4. Harga tertinggi dan terendah
SELECT MAX(harga) AS harga_tertinggi, MIN(harga) AS harga_terendah FROM produk;
 
-- 5. Jumlah produk per kategori
SELECT kategori, COUNT(*) AS jumlah_produk
FROM produk
GROUP BY kategori;
 
-- 6. Kategori yang memiliki lebih dari 2 produk
SELECT kategori, COUNT(*) AS jumlah_produk
FROM produk
GROUP BY kategori
HAVING COUNT(*) > 2;
 
-- 7. Gabungkan nama+kota pelanggan dan supplier (dengan duplikat)
SELECT nama, kota FROM pelanggan
UNION ALL
SELECT nama, kota FROM supplier;
 
-- 8. Semua kota unik dari pelanggan dan supplier (tanpa duplikat)
SELECT kota FROM pelanggan
UNION
SELECT kota FROM supplier;
 
-- 9. Semua data pelanggan beserta transaksinya (INNER JOIN)
SELECT p.*, t.*
FROM pelanggan p
INNER JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan;
 
-- 10. Semua pelanggan + transaksi (termasuk yang tidak pernah transaksi)
SELECT p.*, t.*
FROM pelanggan p
LEFT JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan;
 
-- 11. Rata-rata total belanja per pelanggan
SELECT id_pelanggan, AVG(total_bayar) AS rata_rata_belanja
FROM transaksi
GROUP BY id_pelanggan;
 
-- 12. Pelanggan yang total pembeliannya lebih dari rata-rata total pembelian seluruh pelanggan
SELECT p.nama, SUM(t.total_bayar) AS total_pembelian
FROM pelanggan p
JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan
GROUP BY p.id_pelanggan, p.nama
HAVING SUM(t.total_bayar) > (
    SELECT AVG(total_per_pelanggan)
    FROM (
        SELECT SUM(total_bayar) AS total_per_pelanggan
        FROM transaksi
        GROUP BY id_pelanggan
    ) AS sub
);
 
-- 13. Nama pelanggan dan total jumlah produk yang dibeli
SELECT p.nama, SUM(t.jumlah) AS total_jumlah_produk
FROM pelanggan p
JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan
GROUP BY p.id_pelanggan, p.nama;
 
-- 14. Nama dan kota pelanggan+supplier dalam satu kolom, urut berdasarkan kota
SELECT nama AS nama_pihak, kota FROM pelanggan
UNION
SELECT nama AS nama_pihak, kota FROM supplier
ORDER BY kota;
 
-- 15. Produk kategori 'Elektronik' dan 'Pakaian' dengan harga di atas rata-rata
SELECT * FROM produk
WHERE kategori IN ('Elektronik', 'Pakaian')
  AND harga > (SELECT AVG(harga) FROM produk);
 
-- 16. Jumlah pelanggan per kota, urut terbanyak
SELECT kota, COUNT(*) AS jumlah_pelanggan
FROM pelanggan
GROUP BY kota
ORDER BY jumlah_pelanggan DESC;
 
-- 17. Pelanggan yang tidak pernah bertransaksi (menggunakan NOT EXISTS)
SELECT p.*
FROM pelanggan p
WHERE NOT EXISTS (
    SELECT 1 FROM transaksi t WHERE t.id_pelanggan = p.id_pelanggan
);
 
-- 18. 3 pelanggan dengan total transaksi tertinggi
SELECT p.nama, SUM(t.total_bayar) AS total_transaksi
FROM pelanggan p
JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan
GROUP BY p.id_pelanggan, p.nama
ORDER BY total_transaksi DESC
LIMIT 3;
 
-- 19. Kota dan total transaksi per kota, hanya jika > 500000
SELECT p.kota, SUM(t.total_bayar) AS total_transaksi
FROM pelanggan p
JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan
GROUP BY p.kota
HAVING SUM(t.total_bayar) > 500000;
 
-- 20. Gabungkan nama pelanggan dan nama produk yang pernah dibeli dalam satu kolom
SELECT nama AS nama_item FROM pelanggan
UNION ALL
SELECT pr.nama_produk AS nama_item
FROM produk pr
JOIN transaksi t ON pr.id_produk = t.id_produk;

