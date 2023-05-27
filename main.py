from sympy import symbols, simplify_logic, And, Or,false



MSSV = input("Nhap MSSV: ")
D3 = false
D2 = false
D1 = false
D0 = false

S = symbols('S0:16')
I = symbols('I0:16')


state = [[0 for _ in range(10)] for _ in range(len(MSSV) + 1)]

for i in range(len(MSSV) + 1):
    for j in range(10):
        temp = MSSV[:i] + str(j)
        for k in range(len(temp)):
            if temp[k:] == MSSV[:len(temp) - k]:
                nextState = len(temp[k:])
                curState = len(temp) - 1
                state[len(temp) - 1][j] = nextState

                if nextState == 1:
                    D0 = Or(D0, And(S[curState], I[j]))
                elif nextState == 2:
                    D1 = Or(D1, And(S[curState], I[j]))
                elif nextState == 3:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D1 = Or(D1, And(S[curState], I[j]))
                elif nextState == 4:
                    D2 = Or(D2, And(S[curState], I[j]))
                elif nextState == 5:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                elif nextState == 6:
                    D1 = Or(D1, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                elif nextState == 7:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D1 = Or(D1, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                elif nextState == 8:
                    D3 = Or(D3, And(S[curState], I[j]))
                elif nextState == 9:
                    D3 = Or(D3, And(S[curState], I[j]))
                    D0 = Or(D0, And(S[curState], I[j]))
                elif nextState == 10:
                    D1 = Or(D1, And(S[curState], I[j]))
                    D3 = Or(D3, And(S[curState], I[j]))
                elif nextState == 11:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D1 = Or(D1, And(S[curState], I[j]))
                    D3 = Or(D3, And(S[curState], I[j]))
                elif nextState == 12:
                    D3 = Or(D3, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                elif nextState == 13:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                    D3 = Or(D3, And(S[curState], I[j]))
                elif nextState == 14:
                    D1 = Or(D1, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                    D3 = Or(D3, And(S[curState], I[j]))
                else:
                    D0 = Or(D0, And(S[curState], I[j]))
                    D1 = Or(D1, And(S[curState], I[j]))
                    D2 = Or(D2, And(S[curState], I[j]))
                    D3 = Or(D3, And(S[curState], I[j]))

                break
        else:
            state[len(temp) - 1][j] = 0

print("    ", end="")
print(*range(10))
print("_" * 25)

for i in range(len(MSSV) + 1):
    print(f"S{i}| ", end="")
    print(*state[i])
    
# simplified_D0 = simplify_logic(Boolean(D0[0][:-3]))
# simplified_D1 = simplify_logic(Boolean(D1[0][:-3]))
# simplified_D2 = simplify_logic(Boolean(D2[0][:-3]))
# simplified_D3 = simplify_logic(Boolean(D3[0][:-3]))

# print()
# print("D0:", simplified_D0)
# print("D1:", simplified_D1)
# print("D2:", simplified_D2)
# print("D3:", simplified_D3)
print()
print("D0:", simplify_logic(D0))
print("D1:", simplify_logic(D1))
print("D2:", simplify_logic(D2))
print("D3:", simplify_logic(D3))

