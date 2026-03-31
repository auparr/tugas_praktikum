import java.util.Scanner;
import model.Mahasiswa;
import model.MahasiswaInternasional;

public class Main {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        System.out.print("Masukkan nama mahasiswa lokal: ");
        String nama = input.nextLine();
        System.out.print("Masukkan NIM milik " + nama+": ");
        String nim = input.nextLine();
        System.out.print("Masukkan Kelas "+ nama + ": ");
        String kelas = input.nextLine();
        System.out.print("Masukkan angkatan "+nama+": ");
        int angkatan = input.nextInt();
        input.nextLine();


        Mahasiswa mhs1 = new Mahasiswa( nama, nim, kelas,angkatan);

        mhs1.tampilkanInformasi();
        
        System.out.print("Masukkan nama mahasiswa Internasional: ");
        nama = input.nextLine();
        System.out.print("Masukkan NIM milik " + nama+": ");
        nim = input.nextLine();
        System.out.print("Masukkan Kelas "+ nama + ": ");
        kelas = input.nextLine();
        System.out.print("Masukkan angkatan "+nama+": ");
        angkatan = input.nextInt();
        input.nextLine();
        System.out.print("Masukkan bahasa "+nama+": ");
        String bahasa = input.nextLine();
        System.out.print("Masukkan Negara "+nama+": ");
        String negara = input.nextLine();
        System.out.print("Masukkan Mata Uang "+nama+": ");
        String matauang = input.nextLine();
        System.out.print("Masukkan nilai "+nama+": ");
        int nilai = input.nextInt();
        System.out.print("Masukkan Status Visa " + nama + " (true/false): ");
        boolean statusVisa = input.nextBoolean();


        MahasiswaInternasional mhsinter1 = new MahasiswaInternasional(nama, nim, kelas, angkatan, bahasa, negara, nilai, statusVisa);
    
        mhsinter1.tampilkanInformasi(matauang);

        input.close();
    }

}
