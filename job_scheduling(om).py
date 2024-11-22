class job:
    def __init__(self, jid, dl, pf):
        self.jid = jid
        self.dl = dl
        self.pf = pf
    def __str__(self):
        return f"Job Id: {self.jid}\nJob Deadline: {self.dl}\nJob Profit: {self.pf}\n"

# Input jobs
n = int(input("Enter no of jobs: "))
obj = []
for i in range(n):
    jid = int(input("\nEnter job id: "))
    dl = int(input("Enter job deadline: "))
    pf = int(input("Enter job profit: "))
    obj.append(job(jid, dl, pf))

# Sort jobs by profit in descending order
obj.sort(key=lambda x: x.pf, reverse=True)

# Initialize variables
Tf = 0
cnt = 0
mxobj = max(obj, key=lambda x: x.dl)
mx = mxobj.dl
slot = [0] * mx
opjobs = []

# Scheduling jobs
i = 0
while i < n and cnt < mx:
    j = obj[i].dl - 1
    while j >= 0:
        if slot[j] == 0:
            slot[j] = obj[i].jid
            Tf += obj[i].pf
            opjobs.append(obj[i])
            cnt += 1
            break
        j -= 1
    i += 1

print("\nTotal Profit: ", Tf)
print("\nJobs with optimal profit: ")
for i in range(len(opjobs)):
    print(opjobs[i])

# Display the final job placement
print("\nFinal job placement:")
print(slot)
