def dd(s):
    if (s == "/"):
     return ""
    if (s.count("/") == 1):
        return "/"
    i = s.rfind("/")
    return s[0:i]

def cascade(dict, workingDir, num):
    if workingDir in dict.keys():
        dict[workingDir] += num
    else:
        dict[workingDir] = num
    while dd(workingDir) != "":
        workingDir = dd(workingDir)
        if workingDir in dict.keys():
            dict[workingDir] += num
        else:
            dict[workingDir] = num

file = open('input.txt', 'r')
L = []
file.writelines(L)
lines = file.readlines
tree = {};
pwd = "/";

while True:
    line = line = file.readline()
    if not line:
        break
    parts = line.split()
    if parts[0] == "$":
        if parts[1] == "cd":
            if parts[2] == "..":
                pwd = dd(pwd)
            else:
                if (pwd == "/"):
                    pwd += parts[2]
                else:
                    pwd += "/" + parts[2]
    elif parts[0].isdigit():
        cascade(tree, pwd, int(parts[0]))

unused = 70000000 - tree["/"]
atleast = 30000000 - unused
minimum = 999999999
tot = 0
for key in tree:
    if (tree[key] >= atleast and tree[key] < minimum):
        minimum = tree[key]
    if (tree[key] <= 100000):
        tot += tree[key] 

print("minimumm: ", minimum)
print("sum_under_lim: ", tot)
file.close()
