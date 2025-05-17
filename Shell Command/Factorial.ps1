$num = Read-Host "Enter number"
$fact = 1

while ($num -ne 0) {
    $fact = $fact * $num
    $num = $num - 1
}

Write-Output "Factorial is $fact"
