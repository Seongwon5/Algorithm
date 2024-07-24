array= []

#[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
#for i in range(0,20,2):
#    array.append(i*i)

#아래 코드는 위의 코드와 같은 기능을 한다.
#<리스트 컴프리헨션>
array = [i*i for i in range(0, 20, 2)]
print(array)


array_1 = [i for i in range(10)]
array_2 = [i for i in range(0, 10, 2)]
#for문이 10번 돌지만 리스트 요소로 i가 아닌 1을 선택했기 때문에
#단순히 1이 10번 나열된 리스트가 생성된다.
array_3 = [1 for i in range(10)]

print(array_1)
print(array_2)
print(array_3)

array_4= [i for i in range(10) if i%2 ==0]
print(array_4)

#1 이상 100 미만의 자연수 중 이진수로 바꿨을 때 0이 하나만 포함된 숫자들의 
#합을 구하시오
output = [i for i in range(1,100,1)if ("{:b}".format(i).count("0"))==1]
for i in output:
    print("{} : {:b}".format(i, i))
print("합계:",sum(output))