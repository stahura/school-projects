
def fact(n):
    if n==0:
        return 1
    else:
        return n * fact(n-1)

def square(x):

    return x**2

def reverse(s):
    if s == "":
        return s
    else:
        return reverse(s[1:]) + s[0]

    #ello + h -> llo + e + h - > lo + l + e + H -> o + l + l + e + h

def anagrams(s):
    if s == "":
        return[s]
    else:
        ans = []
        for w in anagrams(s[1:]):
            for pos in range(len(w)+1):
                ans.append(w[:pos]+s[0]+w[pos:])
        return ans

def loopPower(a,n):
    ans = 1
    for i in range(n):
        ans = ans * a
    return ans

def recPower(a,n):

    if n ==0:
        return 1
    else:
        factor = recPower(a, n//2)
        if n%2 == 0:#if n is even
            return factor * factor
        else:       #n is odd
            return factor * factor * a

def recBinSearch(x, nums, low, high):
    if low > high:      #No place left to look, return -1
        return -1
    mid = (low + high) // 2
    item = nums[mid]
    if item == x:
        return mid
    elif x < item:
        return recBinSearch(x, nums, low, mid-1)
    else:
        return recBinSearch(x, mid+1, high)

def search(x, nums):
    return recBinSearch(x, nums, 0, len(nums)-1)

def loopfib(n):

    curr = 1
    prev = 1
    for i in range(n-2):
        curr, prev = curr+prev, curr
    return curr
    #5 curr , prev = 2, 1 -> curr, prev = 3, 2 - > curr, prev = 5, 3

def fib(n):
    if n < 3:
        return 1
    else:
        return fib(n-1) + fib(n-2)

    #Bad algorithm, performs duplicate computations

def selSort(nums):

    n = len(nums)

    for bottom in range(n-1):

        mp = bottom
        for i in range(bottom+1,n):
            if nums[i] < nums[mp]:
                mp = i

        nums[bottom], nums[mp] = nums[mp], nums[bottom]

def merge(lst1, lst2, lst3):
    #split nums in 2 halves
    #sort first half
    #sort second half
    #merge 2 sorted halves back into nums
    i1, i2, i3 = 0, 0, 0

    n1, n2 = len(lst1), len(lst2)
    #loop while lst1 and lst2 have more items
    while i1 < n1 and i2 < n2:
        if lst1[i1] < lst2[i2]: #top of lst1 is smaller
            lst3[i3] = lst1[i1] #copy into current spot in lst3
            i1 = i1 + 1
        else:                   #top of lst2 is smaller
            lst3[i3] = lst2[i2] #copy it into current spot in lst3
            i2 = i2 + 1
        i3 = i3 + 1             #item added to lst3, update position
    #Either lst1 or lst2 is done
    #One of the following loops will execute to finish merge
        
    #copy remaining items, if any, from lst1
    while i1 < n1:
        lst3[i3] = lst1[i1]
        i1 = i1 + 1
        i3 = i3 + 1

    #copy remaining items, if any, from lst2
    while i2 < n2:
        lst3[i3] = lst2[i2]
        i2 = i2 + 1
        i3 = i3 + 1

def mergeSort(nums):
    #if len(nums > 1):
    #   mergeSort first half
    #   mergeSort second half
    #   merge 2 sorted halves into nums

    #Put item of nums in ascending order
    n = len(nums)
    #Do nothing if nums is 0 or 1 item
    if n > 1:
        #Split
        m = n // 2
        nums1, nums2 = nums[:m], nums[m:]
        #Recursively sort each piece
        mergeSort(nums1)
        mergeSort(nums2)
        #merge sorted pieces back into original list
        merge(nums1, nums2, nums)

def linear(x, nums):
    count = 0
    while count != 10000:
        
        for i in range(len(nums)):
            if nums[i] == x:
                print("success")
        nums.append(nums[-1]+1)
        count = count + 1

def binary(x, nums):
    low = 0
    high = len(nums) -1
    count = 0

    for i in range(x-len(nums)):
        addList(nums)
    
    
    while low <= high:
        mid = (low + high)//2
        item = nums[mid]
        if x == item :
            return mid
        elif x < item:
            high = mid - 1
        else:
            low = mid + 1
    return -1
        



listA = [1,2,3,4,5, 6, 7, 8 , 9, 10]

def addList(lista):
    a = lista[-1] + 1
    lista = lista.append(a)
    return lista

    
    


    
    

