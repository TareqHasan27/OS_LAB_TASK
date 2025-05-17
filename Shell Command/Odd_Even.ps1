$num = Read-Host "Enter a number"
$num = [int]$num  

if ($num % 2 -eq 0) {
    Write-Output "$num is even"
}else {
    Write-Output "$num is odd"
}
