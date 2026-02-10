def rata(nums, list_len):
    sum = 0
    for num in nums:
        sum += num
    return float(sum) / list_len

def terbesar(nums):
    max = nums[0]
    for num in nums:
        if max < num:
            max = num
    return max

def terkecil(nums):
    min = nums[0]
    for num in nums:
        if min > num:
            min = num
    return min

def hitungTipe(nums):
    genap = 0
    ganjil = 0
    
    for num in nums:
        if num % 2 == 0:
            genap += 1
        else:
            ganjil +=1
            
    return {"ganjil": ganjil, "genap": genap}
    
    
def main():
    nums = []
    try:
        list_len = int(input("Masukkan jumlah elemen list: "))
        
        if list_len <= 0:
            print("jumlah elemen tidak boleh kurang dari atau sama dengan 0")
            exit()

        for i in range(list_len):
            num = int(input(f"Masukkan angka ke {i+1}: "))
            nums.append(num)
            
    except:
        print("Error: Input invalid")
        exit()
        
                
    print(f"""
Rata-rata: {rata(nums, list_len)}
Angka terbesar: {terbesar(nums)}
Angka terkecil: {terkecil(nums)}
Jumlah ganjil: {hitungTipe(nums)["ganjil"]}
Jumlah genap: {hitungTipe(nums)["genap"]}
        """)

if __name__ == "__main__":
    main()
