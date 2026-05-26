-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- Toko Online -- -- -- -- -- -- -- --
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

CREATE DATABASE IF NOT EXISTS toko_online;
USE toko_online;

CREATE TABLE pelanggan (
	id_pelanggan INT PRIMARY KEY,
    nama VARCHAR(50),
    alamat VARCHAR(100)
);

INSERT INTO pelanggan VALUES
(1, 'Andi Saputra', 'Jakarta'),
(2, 'Agus Salim', 'Bandung'),
(3, 'Budi Santoso','Surabaya'),
(4, 'Alia Rahma', 'Yogyakarta'),
(5, 'Sari Melati', 'Semarang'),
(6, 'Ahmad Fadli', 'Bogor');

CREATE TABLE produk (
	id_produk INT PRIMARY KEY,
    nama_produk VARCHAR(50),
    kategori VARCHAR(20),
    harga INT
);

INSERT INTO produk VALUES
(1,'Kopi Hitam', 'Minuman', 15000),
(2,'Teh Manis', 'Minuman', 10000),
(3,'Roto Bakar', 'Makanan', 20000),
(4,'Kopi Susu', 'Minuman', 18000),
(5,'Nasi Goreng', 'Makanan', 30000),
(6,'Ayam Geprek', 'Makanan', 25000),
(7,'Air Mineral', 'Minuman', 8000);

CREATE TABLE transaksi (
	id_transaksi INT PRIMARY KEY,
    id_pelanggan  INT,
    total_bayar INT,
    FOREIGN KEY (id_pelanggan) REFERENCES pelanggan (id_pelanggan)
);

INSERT INTO transaksi VALUES
(1,1,20000),
(2, 2, NULL),
(3, 3, 250000),
(4, 1, 30000),
(5, 4, 50000),
(6, 5, NULL),
(7, 1, 10000),
(8, 3, 15000),
(9, 4, 18000);

-- 3
ALTER TABLE pelanggan
ADD COLUMN  email VARCHAR(50);

-- 4
ALTER TABLE produk
MODIFY COLUMN harga DECIMAL(10,2);

-- 5
ALTER TABLE pelanggan
DROP COLUMN email;

-- 1
SELECT * FROM pelanggan
WHERE nama LIKE 'A%';

-- 2 
SELECT * FROM produk
WHERE nama_produk LIKE '%Kopi%';

-- 3
SELECT * FROM produk 
WHERE kategori IN ('Makanan', 'Minuman');

-- 4
SELECT * FROM produk
WHERE harga BETWEEN 10000 AND 20000;

-- 5
SELECT * FROM transaksi
WHERE total_bayar IS NULL;

-- 6
SELECT p.nama 
FROM pelanggan p 
JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan 
WHERE t.total_bayar > 200000;

-- 7
SELECT AVG(harga) 
FROM produk 
WHERE kategori = 'Minuman' AND harga > 10000;

-- 8
INSERT INTO pelanggan VALUES 
(7, 'Sinta Ayu', 'Solo');

-- 9
UPDATE produk
SET harga = 12000
WHERE nama_produk = 'Teh Manis';

-- 10
DELETE FROM produk
WHERE harga < 15000;

-- 11
SELECT p.nama, SUM(t.total_bayar) AS total_transaksi 
FROM pelanggan p 
LEFT JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan 
GROUP BY p.nama;

-- 12
SELECT p.* FROM pelanggan p 
LEFT JOIN transaksi t ON p.id_pelanggan = t.id_pelanggan 
WHERE t.id_transaksi IS NULL;

-- 13
SELECT kategori, COUNT(*) AS jumlah_produk 
FROM produk 
GROUP BY kategori;

-- 14
SELECT * FROM produk 
ORDER BY harga DESC LIMIT 2;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- -- -- -- -- -- Perpustakaan -- -- -- -- -- -- -- -
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

CREATE DATABASE IF NOT EXISTS perpustakaan;
USE perpustakaan;

CREATE TABLE anggota (
    id_anggota INT PRIMARY KEY,
    nama VARCHAR(50),
    kota VARCHAR(50)
);

INSERT INTO anggota VALUES
(1, 'Rina Marlina', 'Jakarta'),
(2, 'Budi Hartono', 'Bandung'),
(3, 'Andi Saputra', 'Surabaya'),
(4, 'Siti Aminah', 'Semarang'),
(5, 'Ahmad Zaki', 'Malang'),
(6, 'Alia Fadilah', 'Yogyakarta');

CREATE TABLE buku (
    id_buku INT PRIMARY KEY,
    judul VARCHAR(100),
    penulis VARCHAR(50),
    tahun_terbit INT
    kategori VARCHAR(30),
    stok INT
);

INSERT INTO buku VALUES
(1, 'Pemrograman Dasar', 'Eka Putra', 2019, 'Teknologi', 5),
(2, 'Basis Data Lanjut', 'Siti Kurnia', 2020, 'Teknologi', 3),
(3, 'Matematika Diskrit', 'Joko Widodo', 2018, 'Matematika', 4),
(4, 'Algoritma dan Struktur Data', 'Rina Kartika', 2021, 'Teknologi', 6),
(5, 'Sejarah Indonesia', 'Arif Nugroho', 2017, 'Sosial', 2),
(6, 'Psikologi Remaja', 'Tari Hapsari', 2019, 'Psikologi', 3),
(7, 'Filsafat Ilmu', 'Dedi Santoso', 2015, 'Filsafat', 1);

CREATE TABLE peminjaman (
    id_pinjam INT PRIMARY KEY,
    id_anggota INT,
    id_buku INT,
    tanggal_pinjam DATE,
    tanggal_kembali DATE,
    FOREIGN KEY (id_anggota) REFERENCES anggota (id_anggota),
    FOREIGN KEY (id_buku) REFERENCES buku (id_buku)
);

INSERT INTO peminjaman VALUES
(1, 1, 2, '2024-03-10', '2024-03-17'),
(2, 2, 3, '2024-03-12', NULL),
(3, 3, 1, '2024-03-15', '2024-03-22'),
(4, 1, 5, '2024-03-20', NULL),
(5, 4, 6, '2024-04-01', '2024-04-10'),
(6, 5, 2, '2024-04-02', NULL);

-- 3
ALTER TABLE anggota
ADD COLUMN  email VARCHAR(50);

-- 4
ALTER TABLE buku
MODIFY COLUMN tahun_terbit VARCHAR(4);

-- 5
ALTER TABLE anggota
DROP COLUMN email;

-- 1
SELECT * FROM anggota
WHERE nama LIKE 'A%';

-- 2
SELECT * FROM buku
WHERE penulis LIKE '%Putra%';

-- 3
SELECT * FROM buku
WHERE kategori IN ('Teknologi', 'Matematika');

-- 4
SELECT * FROM buku
WHERE tahun_terbit BETWEEN '2018' AND '2020';

-- 5
SELECT * FROM peminjaman
WHERE tanggal_kembali IS NULL;

-- 6
SELECT a.nama 
FROM anggota a 
JOIN peminjaman p ON a.id_anggota = p.id_anggota 
WHERE p.judul = 'Sosial';

-- 7
SELECT AVG(stok) 
FROM buku;

-- 8
INSERT INTO anggota VALUES 
(7, 'Lina Khairunnisa', 'Depok');

-- 9
UPDATE buku
SET stok = 3
WHERE judul = 'Filsafat Ilmu';

-- 10
DELETE FROM buku
WHERE stok < 2;

-- 11
SELECT a.nama, COUNT(p.id_pinjam) AS total_peminjaman 
FROM anggota a 
LEFT JOIN peminjaman p ON a.id_anggota = p.id_anggota 
GROUP BY a.nama;

-- 12
SELECT a.* FROM anggota a
LEFT JOIN peminjaman p ON a.id_anggota = p.id_anggota 
WHERE p.id_pinjam IS NULL;

-- 13
SELECT * FROM buku
ORDER BY stok DESC LIMIT 3;

-- 14
SELECT AVG(stok) 
FROM buku 
WHERE kategori = 'Teknologi';