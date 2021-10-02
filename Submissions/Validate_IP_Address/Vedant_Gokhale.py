# Validate an IP Address
# Vedant Gokhale (gokhalevedant06)

# Explanation
# 1) Split the string using split method 
# 2) Check if length = 4 else return False (Invalid IP)
# 3) Append all possible integers(0-255) in a list 
# 4) Initialize a temp string and a counter 
# 5) Find for '.' in the original string using for loop and store all the integers before '.' in temp
# 6) If '.' is found in original string and list contains a string equal to temp then increase counter by 1, assign temp = ''
# 7) If counter == 4 IP adress is valid, return True else return False 

#Time Complexity: O(n)
#Space Complexity: O(1)

# Function which checks whether IP address is valid or not
def isValid(s):
    s1 = s.split('.')
    if (len(s1)!=4): return False
    
    l = []
    for i in range(256):
        l.append(str(i))
    
    counter = 0;
    temp = ''
    for i in range(len(s)):
        if (s[i]!='.'):
            temp = temp + s[i]
        else:
            if(l.count(temp)!=0): counter = counter + 1
            temp = ''
    if (l.count(temp)!=0): counter = counter + 1
    if (counter == 4): return True
    else: return False
        

#  Driver Code 
if __name__=="__main__":
    if(isValid('222.111.111.111')):
        print(1)
    else:
        print(0)
    if(isValid('5555..555')):
        print(1)
    else:
        print(0)
