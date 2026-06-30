-- Active: 1779778255598@@127.0.0.1@3306@mysql
Create Database if not exists final_task;
use final_task;

-- 1. Tabel Koleksi_Game (Tabel Master)
CREATE TABLE Koleksi_Game (
    ID_Game INT PRIMARY KEY AUTO_INCREMENT,
    Nama_Game VARCHAR(100) NOT NULL,
    Developer VARCHAR(100) NOT NULL,
    Jaringan_Chain VARCHAR(50) DEFAULT 'Ethereum'
);

INSERT INTO Koleksi_Game (Nama_Game, Developer, Jaringan_Chain) VALUES
('Axie Infinity', 'Sky Mavis', 'Ronin'),
('Pixels', 'Pixels Online', 'Ronin'),
('Big Time', 'Big Time Studios', 'Ethereum'),
('The Sandbox', 'Pixowl', 'Ethereum'),
('Decentraland', 'Decentraland Foundation', 'Ethereum'),
('Illuvium', 'Illuvium Labs', 'Immutable X'),
('Gods Unchained', 'Immutable', 'Immutable X'),
('Alien Worlds', 'Dacoco', 'WAX'),
('Splinterlands', 'Splinterlands', 'Hive'),
('Pegaxy', 'Mirai Labs', 'Polygon');

-- 2. Tabel Aset_Digital (Tabel Master)
CREATE TABLE Aset_Digital (
    ID_Aset INT PRIMARY KEY AUTO_INCREMENT,
    ID_Game INT,
    Nama_Item VARCHAR(100) NOT NULL,
    Tingkat_Rarity VARCHAR(20) CHECK (Tingkat_Rarity IN ('Common', 'Rare', 'Epic', 'Legendary')),
    Atribut_Damage INT DEFAULT 0,
    FOREIGN KEY (ID_Game) REFERENCES Koleksi_Game(ID_Game)
);

INSERT INTO Aset_Digital (ID_Game, Nama_Item, Tingkat_Rarity, Atribut_Damage) VALUES
(1, 'Mystic Axie Beast', 'Legendary', 120),
(1, 'Plant Axie Tank', 'Common', 40),
(2, 'Farmland Plot #1024', 'Rare', 0),
(2, 'Popberry Seed Pack', 'Common', 0),
(3, 'Time Warden Armor', 'Epic', 250),
(3, 'Quantum Blade', 'Legendary', 400),
(4, 'Cyberpunk Voxel Avatar', 'Rare', 0),
(6, 'Illuvial Ranger', 'Epic', 180),
(7, 'Demogorgon Core Card', 'Legendary', 300),
(10, 'Silver Apollo Mecha Horse', 'Rare', 90);

-- 3. Tabel Pemain (Tabel Master User)
CREATE TABLE Pemain (
    ID_Pemain INT PRIMARY KEY AUTO_INCREMENT,
    Username_Game VARCHAR(50) UNIQUE NOT NULL,
    Alamat_Wallet_Kripto VARCHAR(64) UNIQUE NOT NULL,
    Tgl_Registrasi DATE NOT NULL
);

INSERT INTO Pemain (Username_Game, Alamat_Wallet_Kripto, Tgl_Registrasi) VALUES
('CryptoKnight', '0x71C7656EC7ab88b098defB751B7401B5f6d8976F', '2023-01-15'),
('RoninMaster', 'ronin:1a2b3c4d5e6f7g8h9i0j', '2023-02-20'),
('PixelFarmer', 'ronin:9z8y7x6w5v4u3t2s1r0q', '2023-03-10'),
('TimeTraveler', '0x3F5CE5FBFe3E9af3971dD833D26bA9b5C936f0bE', '2023-04-05'),
('VoxelBuilder', '0x8B0E33a41B2E3f3C0fBc6260a4C15A43E63c19e5', '2023-05-12'),
('CardSlayer', '0xD1220A0cf47c7B9Be7A2E6BA89F429762e7b9aDb', '2023-06-18'),
('MechaRider', '0x9A2F45330F7C2B4B276182Df73D49DCA1524328E', '2023-07-22'),
('AlienMiner', 'wax:abc12.wam', '2023-08-30'),
('SplinterKing', 'hive:splinter_king99', '2023-09-14'),
('WhaleInvestor', '0x54F1C7656EC7ab88b098defB751B7401B5f6d8977A', '2023-10-01');

-- 4. Tabel Kepemilikan_Item (Tabel Transaksi/Junction)
CREATE TABLE Kepemilikan_Item (
    ID_Pemilik INT PRIMARY KEY AUTO_INCREMENT,
    ID_Pemain INT,
    ID_Aset INT,
    Tgl_Akuisisi DATE NOT NULL,
    Status_Equipped BOOLEAN DEFAULT FALSE,
    FOREIGN KEY (ID_Pemain) REFERENCES Pemain(ID_Pemain),
    FOREIGN KEY (ID_Aset) REFERENCES Aset_Digital(ID_Aset)
);

INSERT INTO Kepemilikan_Item (ID_Pemain, ID_Aset, Tgl_Akuisisi, Status_Equipped) VALUES
(1, 6, '2023-11-01', TRUE),
(2, 1, '2023-11-02', TRUE),
(2, 2, '2023-11-03', FALSE),
(3, 3, '2023-11-05', TRUE),
(3, 4, '2023-11-06', FALSE),
(4, 5, '2023-11-10', TRUE),
(5, 7, '2023-11-15', TRUE),
(6, 9, '2023-11-20', FALSE),
(7, 10, '2023-11-25', TRUE),
(10, 8, '2023-12-01', FALSE);

-- 5. Tabel Riwayat_Transfer (Tabel Log Transaksi)
CREATE TABLE Riwayat_Transfer (
    ID_Transfer INT PRIMARY KEY AUTO_INCREMENT,
    ID_Aset INT,
    Wallet_Pengirim VARCHAR(64) NOT NULL,
    Wallet_Penerima VARCHAR(64) NOT NULL,
    Waktu_Transaksi TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (ID_Aset) REFERENCES Aset_Digital(ID_Aset)
);

INSERT INTO Riwayat_Transfer (ID_Aset, Wallet_Pengirim, Wallet_Penerima, Waktu_Transaksi) VALUES
(1, 'ronin:00000000000000000000', 'ronin:1a2b3c4d5e6f7g8h9i0j', '2023-11-02 10:00:00'),
(2, 'ronin:99998888777766665555', 'ronin:1a2b3c4d5e6f7g8h9i0j', '2023-11-03 14:30:00'),
(6, '0x8B0E33a41B2E3f3C0fBc6260a4C15A43E63c19e5', '0x71C7656EC7ab88b098defB751B7401B5f6d8976F', '2023-11-01 09:15:00'),
(3, 'ronin:55554444333322221111', 'ronin:9z8y7x6w5v4u3t2s1r0q', '2023-11-05 16:45:00'),
(4, 'ronin:11112222333344445555', 'ronin:9z8y7x6w5v4u3t2s1r0q', '2023-11-06 08:20:00'),
(5, '0x1234567890abcdef1234567890abcdef12345678', '0x3F5CE5FBFe3E9af3971dD833D26bA9b5C936f0bE', '2023-11-10 11:11:11'), 
(7, '0x9988776655443322110099887766554433221100', '0x8B0E33a41B2E3f3C0fBc6260a4C15A43E63c19e5', '2023-11-15 13:25:00'),
(9, '0xaabbccddeeff0011223344556677889900112233', '0xD1220A0cf47c7B9Be7A2E6BA89F429762e7b9aDb', '2023-11-20 19:50:00'),
(10,'0xffeeccbbaa0099887766554433221100ffeeccbb', '0x9A2F45330F7C2B4B276182Df73D49DCA1524328E', '2023-11-25 21:30:00'),
(8, '0x7777777777777777777777777777777777777777', '0x54F1C7656EC7ab88b098defB751B7401B5f6d8977A', '2023-12-01 23:59:59');

SELECT * FROM Koleksi_Game;
-- DROP TABLE Kepemilikan_Item;
-- DROP TABLE Riwayat_Transfer;
-- DROP TABLE Aset_Digital;
-- DROP TABLE Koleksi_Game;
-- DROP TABLE Pemain;
SELECT * FROM Aset_Digital;
SELECT * FROM Pemain;
SELECT * FROM Kepemilikan_Item;
SELECT * FROM Riwayat_Transfer;

-- INSERT INTO Pemain (Username_Game, Alamat_Wallet_Kripto, Tgl_Registrasi) VALUES
-- ('Suxxon', '0xabcdefabcdefabcdefabcdefabcdefabcdefabcd', '2024-01-01');

-- DELETE FROM Pemain
-- WHERE Username_Game = 'Suxxon';

UPDATE Pemain
SET Alamat_Wallet_Kripto = '0xabcdefabcdefabcdefabcdefabcdefabcdefabcd',
    Username_Game = 'Suxxon'
WHERE Username_Game = 'WhaleInvestor';