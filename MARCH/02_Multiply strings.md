###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/462e0d5b-d91b-4fa1-9410-70bfd57b3631" />

###### I N T U I T I O N
      Core Intuition: Digit-by-Digit MultiplicationOkkasari ee points choodu:
      
      The Container: Rendu numbers $n1$ and $n2$ length lo unte, avi multiply chesinappudu 
      vachhe max length $n1 + n2$ untundhi.
      
      Anduke manam oka res vector ni aa size tho start chestham.Reverse Engineering: 
      Strings ni reverse nundi (n-1 to 0) loop chestham. 
      
      Endukante multiplication eppudu units place nundi start avvali kabatti.
      The "i + j + 1" Trick: 
      
      Ide main logic thammudu. num1[i] and num2[j] multiply chesinappudu:
      
      Vachhe product ni i + j + 1 index (current position) daggara unna 
      value ki add chestham.Aa total sum lo 
      
      vachhe Carry ni ventane daanikante mundu unna position i + j ki 
      transfer chestham.Cleaning Up: 
      
      Last ki aa vector lo unna zeros ni (leading zeros) remove chesi
      string ga marchithe mana answer ready!
      
###### C O D E
```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        // Result array can have at most n1 + n2 digits
        vector<int> res(n1 + n2, 0);
        
        // Loop from right to left (Units place first)
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                // Char to Int conversion
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Position logic: i+j is carry position, i+j+1 is current digit position
                int sum = mul + res[i + j + 1];
                
                res[i + j + 1] = sum % 10; // Current digit
                res[i + j] += sum / 10;    // Adding carry to the previous position
            }
        }
        
        // Convert vector to string, skip leading zeros
        string result = "";
        for (int p : res) {
            if (!(result.empty() && p == 0)) {
                result += to_string(p);
            }
        }
        
        return result.empty() ? "0" : result;
    }
};
```
