def add(a, b):
    a = int(a)
    b = int(b)
    c = a + b
    return str(c)

def isPali(c):
    len1 = len(c)
    flg = True
    for i in range(len1):
        if c[i] != c[len1-i-1]:
            flg = False
            break
    if flg == True:
        return True
    else:
        return False;

num1, k = input().split(" ")
k = int(k)
num2 = num1[::-1]

if isPali(num1):
    print(num1)
    print(0)
    exit(0)

for i in range(1, k+1):
    num1 = add(num1, num2)
    if isPali(num1):
        print(num1)
        print(i)
        exit(0)
    num2 = num1[::-1]

print(num1)
print(k)

