def rev(s):
    return s[::-1]

def add(s1, s2):
    a1 = int(s1)
    a2 = int(s2)
    return str(a1 + a2)

def judge(s):
    if int(s) == 0:
        return True
    n = len(s)
    for i in range(int(n/2)):
        if(s[i] != s[n-i-1]):
            return False
    return True

s = input()
if(judge(s)):
    print(s + " is a palindromic number.")
    exit(0)
for i in range(10):
    s2 = rev(s)
    sum = add(s, s2)
    print(s + " + " + s2 +" = " + sum)
    if(judge(sum)):
        print(sum + " is a palindromic number.")
        exit(0)
    s = sum

print("Not found in 10 iterations.")


