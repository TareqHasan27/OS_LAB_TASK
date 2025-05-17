$n = Read-Host "Enter how many numbers you want to sum"
$n = [int]$n

$sum = 0

for ($i = 1; $i -le $n; $i++) {
    $num = Read-Host "Enter number $i"
    $sum += [int]$num
}

Write-Host "The sum of $n numbers is: $sum"