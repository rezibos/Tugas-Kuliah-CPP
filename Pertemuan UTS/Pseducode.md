START

FUNCTION tambahBarang()

    DECLARE barang AS Item
    DECLARE pilihan AS CHAR

    REPEAT
        DISPLAY "===================================="
        DISPLAY "Masukkan ID Barang: "
        INPUT barang.id_barang
        DISPLAY "Masukkan Nama Barang: "
        INPUT barang.nama_barang
        DISPLAY "Masukkan Harga Barang: "
        INPUT barang.harga_barang
        DISPLAY "Masukkan Stok Barang: "
        INPUT barang.stok_barang

        ADD barang TO inventaris
        DISPLAY "Barang Berhasil Ditambahkan!"
        DISPLAY "===================================="
        DISPLAY "Apakah Anda Ingin Menambahkan Barang (y/n): "
        INPUT pilihan
        DISPLAY "===================================="
    UNTIL pilihan != 'y' AND pilihan != 'Y'

END FUNCTION

FUNCTION tampilkanSemuaBarang()
    
END FUNCTION

FUNCTION ProsesTransaksi()
    
END FUNCTION

FUNCTION TampilkanMetodePembayaran()
    
END FUNCTION

FUNCTION BuatLaporanPenjualan()
    
END FUNCTION

FUNCTION SimpanTransaksikeFile()
    
END FUNCTION

MAIN
    DECLARE pilihan AS INTEGER

    REPEAT
        DISPLAY "===================================="
        DISPLAY "Aplikasi Kasir Suka Maju Bersama"
        DISPLAY "===================================="
        DISPLAY "1. Tambah Barang Baru"
        DISPLAY "2. Tampilkan Semua Barang"
        DISPLAY "3. Proses Transaksi"
        DISPLAY "4. Tampilkan Metode Pembayaran"
        DISPLAY "5. Buat Laporan Penjualan"
        DISPLAY "6. Simpan Transaksi ke File"
        DISPLAY "7. Keluar"
        DISPLAY "===================================="
        DISPLAY "Masukkan pilihan Anda: "
        INPUT pilihan
        DISPLAY "===================================="

        SWITCH pilihan
            CASE 1:
                CALL tambahBarang()
            CASE 2:
                CALL tampilkanSemuaBarang()
            CASE 3:
                CALL ProsesTransaksi()
            CASE 4:
                CALL TampilkanMetodePembayaran()
            CASE 5:
                CALL BuatLaporanPenjualan()
            CASE 6:
                CALL SimpanTransaksikeFile()
            CASE 7:
                EXIT PROGRAM
            DEFAULT:
                DISPLAY "Pilihan tidak valid. Coba lagi."
        END SWITCH
    UNTIL pilihan = 7

    DISPLAY "Anda Keluar Dari Program"
END MAIN

END
