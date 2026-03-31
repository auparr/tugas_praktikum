package model;

public class MahasiswaInternasional extends Mahasiswa{
    public String bahasa;
    public String negaraAsal;
    public int nilai;
    public boolean  statusVisa;

    public MahasiswaInternasional(String nama, String nim, String kelas, int angkatan, String bahasa, String negaraAsal, int nilai, boolean statusVisa) {
        super(nama, nim, kelas, angkatan);
        this.bahasa = bahasa;
        this.negaraAsal = negaraAsal;
        this.nilai = nilai;
        this.statusVisa = statusVisa;
    }

    public void tampilkanInformasi(String matauang) {
        super.tampilkanInformasi();
        System.out.println("=== INFORMASI TAMBAHAN ===");
        System.out.println("Bahasa\t : " + bahasa);
        System.out.println("Negara\t : " + negaraAsal);
        System.out.println("Uang\t : " + matauang);

        System.out.println("=== Tugas ===");
        System.out.println("Nilai\t:" + nilai);
        if(nilai >= 75) {
            System.out.println("Mahasiswa LULUS");
        }
        else if (nilai >= 60 && nilai <= 74)
        {
            System.out.println("Remedial diperbolehkan");
        }
        else if (nilai < 60 && nilai >= 0)
        {
            System.out.println("Harus mengulang, diperbolehkan memperpanjang masa tinggal (kepulangan ditunda)");
        }
        else {
            System.out.println("Nilai tidak valid");
        }

        System.out.println("\nStatus VISA:" + statusVisa);

        if (statusVisa == true)
        {
            System.out.println("Visa aktif, mahasiswa diizinkan tinggal");
        }
        else if (statusVisa == false) {
            System.out.println("Visa tidak aktif, segera lakukan perpanjangan");
        }

        if((nilai < 60 && nilai >= 0) && statusVisa == false)
        {
            System.out.println("PERINGATAN: Mahasiswa harus mengulang dan segera memperpanjang Visa!");
        }
    }
}
