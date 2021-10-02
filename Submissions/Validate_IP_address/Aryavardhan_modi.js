// Aryavardhan Modi
// APPROACH :
// Generally there 2 types of ip addresses either 32bit or 128 bit address
// every ip address has a specific pattern on basis of which we can judge whether its a valid one or not

// Time complexity : O(n)
// Space Complexity : O(1)

function validIPAddress(IP) 
{
    const ip4 = /^((\d|[1-9]\d|1\d\d|2([0-4]\d|5[0-5]))\.){4}$/; 
    // regex pattern for 32 bit ip address as it consists of numerbers (0-255).(0-255).(0-255).(0-255)
    const ip6 = /^([\da-f]{1,4}:){8}$/i;
    // where as an 128bit contains alpha-numeric terms because its in hexadecimal and separated by ':'
    return ip4.test(IP + '.') ? '1' : ip6.test(IP + ':') ? '1' : '0'; // checking thorugh ternary expression if matches with either pattern or not
}

check1 = validIPAddress("222.111.111.111")
console.log(check1)

check2 = validIPAddress("5555..555")
console.log(check2)