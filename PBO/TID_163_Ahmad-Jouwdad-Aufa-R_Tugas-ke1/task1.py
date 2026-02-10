while True:
    try:
        print("--------------------")
        print("Kalkulator sederhana")
        print("--------------------")
        
        num1 = int(input("Masukkan angka pertama: "))
        num2 = int(input("Masukkan angka kedua: "))
        
        if num2 == 0:
            print("\npembagi tidak boleh 0.\nsilahkan input ulang.\n")
            continue
        
        add = num1 + num2
        sub = num1 - num2
        multi = num1 * num2
        div = float(num1) / num2
        
        print(f"""
Hasil Penjumlahan: {add}
Hasil Pengurangan: {sub}
Hasil Perkalian: {multi}
Hasil Pembagian: {div}
                """)
        
        break
    except:
        print("Error: inputnya ga valid.\nsilahkan input ulang.\n")
