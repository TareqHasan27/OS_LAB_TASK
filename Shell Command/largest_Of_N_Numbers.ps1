$n = Read-Host "How many numbers?"
$n = [int]$n  

$largest = $null  

for ($i = 0; $i -lt $n; $i++) {
    $num = Read-Host "Enter number $($i + 1)"
    $num = [int]$num  

    if ($largest -eq $null -or $num -gt $largest) {
        $largest = $num
    }
}

Write-Output "Largest number is $largest"
