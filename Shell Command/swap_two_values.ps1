$a = Read-Host "Enter first value"
$b = Read-Host "Enter second value"

Write-Host "Before swap: a = $a, b = $b"

$temp = $a
$a = $b
$b = $temp

Write-Host "After swap: a = $a, b = $b"