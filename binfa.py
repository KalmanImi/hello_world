import statistics

a = open("binprob.txt","r")
c = a.read()

vege = 100
T = "01010100"
C = "01000011"
A = "01000001"
G = "01000111"

##T = "00101010"
##C = "11000010"
##A = "10000010"
##G = "11100010"


b = ""

def TCAG(betu):
    if betu == 'T':
        return T
    elif betu == 'C':
        return C
    elif betu == 'A':
        return A
    elif betu == 'G':
        return G

for i in range(0,len(c)):
    try:
        b += TCAG(c[i])
    except (UnboundLocalError, TypeError):
        ''

        
class BinFa:
    def __init__(self, MI, MENNYI):
        self.mi = MI
        self.mennyi = MENNYI

q = []
p = []

i = 0
while (i < len(b)):
    if b[i] not in q:
        q.append(b[i])
        p.append(1)
        i+=1
    for j in reversed(range(0,len(q))):
        num = 0
        tmp = ""
        breakj = False
        try:
            for k in range(0,len(q[j])):
                if (q[j][k] == b[i+k]):
                    num += 1
                    tmp += b[i+k]
                if num == len(q[j]):
                    q.append(tmp+b[i+k+1])
                    p.append(len(tmp)+1)
                    i+=len(q[j])+1
                    #print((len(q[j])*"---")+q[j][-1]+"("+str(p[j])+")")
                    #print("---"+str(j)+"("+q[j]+")")
                    #print(i)
                    breakj = True
                    break
            if breakj == True:
                break
        except:
            ''

for i in range(0,len(q)):
    print('---'*(p[i]+1) + q[i][-1] + '(' + str(p[i]) + ')')

depth = max(p)

##def mean(p):
##    db = 0
##    sum0 = 0
##    for i in p:
##        db+=1
##        sum0+=i
##    return sum0/db
del q[len(q)-1]
del p[len(p)-1]

avgkonk = []    
avglista = []

for i in range(0,len(q)):
    k = 0
    for j in range(0,len(q)):
        if q[i] != q[j] and q[i][0:len(q[i])] == q[j][0:len(q[i])]:
            #print(q[i],q[j])
            k = 1
            break
    #print(k)
    if k == 1:
        continue
    elif k == 0:
        avglista.append(p[i])
        avgkonk.append(q[i])
        #print(q[i] + " appended.")
        continue


#print(len(p),len(avglista))
print("Depth: " + str(depth))
print("Mean: " + str(statistics.mean(avglista)))
print("Var: " + str(statistics.stdev(avglista)))


##
##for i in range(0,len(q)):
##    print(q[i]+"-->("+str(p[i])+")")
