echo "Enter a number"
read num
fact=1
while [ $num -gt 1 ]
do
 fact=$((fact * num)) 
 num=$((num - 1))
done
echo $fact

------------------------------------------------------------------
#sum of digits of a given number
echo "Enter a number"
read x
sum=0
while [ $x -gt 0 ]
do
rem=` expr $x % 10 `
sum=` expr $sum + $rem `
x=` expr $x / 10 `
done
echo 'sum of digits is' $sum

------------------------------------------------------------------
#sum of first n natural numbers
echo "Enter a number"
read n
while [ $n -ge 1 ]
do
n1=` expr $n1 + $n `
n=` expr $n - 1 `
done
echo 'sum of first n numbers' $n1

------------------------------------------------------------------
#palindrome or not
echo "Enter a number"
read num
s=0
rev=""
temp=$num
while [ $num -gt 0 ]
do
s=$(( $num % 10 )) 
num=$(( $num / 10 )) 
rev=$( echo ${rev}${s} ) 
done
if [ $temp -eq $rev ];
then
echo "Number is palindrome"
else
echo "Number is NOT palindrome"
fi

------------------------------------------------------------------
#gcd of two numbers
echo "Enter first number"
read g1
echo "Enter second number"
read g2
gcd=0
if [ $g1 -gt $g2 ]
then g=$(($g1))
else g=$(($g2))
fi
i=1
while [ $i -le $g ]
do
if (( $g1 % $i == 0 && $g2 % $i == 0)) 
then 
gcd=$(($i))
fi
i=` expr $i + 1 `
done 
echo 'gcd of' $g1 'and' $g2 'is' $gcd

------------------------------------------------------------------
#fibonacci series upto n terms
echo "Enter n:"
read n
i=3
a=0
b=1
temp=$b
echo "Series:"
echo $a
echo $b
while [ $i -le $n ]
do
 echo $temp
 a=$b
 b=$temp
 temp=` expr $a + $b `
 i=` expr $i + 1 `
done

-----------------------------------------------------------------

#prime numbers upto a given number
echo "Enter n:"
read n
i=2
echo "Prime numbers:"
while [ $i -le $n ]
do
 a=2
 count=0
 while [ $a -lt $i ]
 do
 b=` expr $i % $a `
 if [ $b -eq 0 ]
 then
 count=` expr $count + 1 `
 fi
 a=` expr $a + 1 `
 done
 if [ $count -eq 0 ]
 then
 echo $i
 fi
 i=` expr $i + 1 `
done

-----------------------------------------------------------------
#armstrong numbers upto a given number
echo "Enter n:"
read n
i=1
while [ $i -le $n ]
do
 sum=0
 
 temp=$i
 count=0
 while [ $temp -ne 0 ]
 do
 count=` expr $count + 1 `
 temp=` expr $temp / 10 `
 done
 temp=$i
 while [ $temp -ne 0 ]
 do
 rem=` expr $temp % 10 `
rem=$(($rem ** $count))
 sum=` expr $sum + $rem `
 temp=` expr $temp / 10 `
 
 done
 if [ $sum -eq $i ]
 then
 echo $i
 fi
 i=` expr $i + 1 `
done

-----------------------------------------------------------------
#krishnamurthy numbers upto n
echo "Enter n:"
read n
i=1
while [ $i -le $n ]
do
sum=0
 temp=$i
 while [ $temp -ne 0 ]
 do
 rem=` expr $temp % 10 `
 fact=1
 k=1
 while [ $k -le $rem ]
 do
 fact=$(($fact * $k))
 k=` expr $k + 1 `
 done 
 sum=` expr $sum + $fact `
 temp=` expr $temp / 10 ` 
 done
 if [ $sum -eq $i ]
 then
 echo $i
 fi
 i=` expr $i + 1 `
done
