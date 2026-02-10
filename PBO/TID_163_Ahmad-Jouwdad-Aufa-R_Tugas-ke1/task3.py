fname = input("Masukkan nama depan: ")
lname = input("Masukkan nama belakang: ")

if not fname.strip():
    print("nama depan wajib terisi")
    exit()

if lname.strip():
    full_name = fname + " " + lname
else:
    full_name = fname

"""
 sebenarnya bisa pakai print(full_name[::-1]),
 tapi karena sifatnya tugas jadi saya cari cara lain
"""
 
reversed_name = ""
for i in range(len(full_name)):
    reversed_name += full_name[-i-1]
print(reversed_name)
