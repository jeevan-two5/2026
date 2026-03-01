######  IMAGE
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/8bb9e416-d63e-47e2-9f60-06678a732cf3" />

###### I N T U I T I O N

Gemini said
Arey thammudu, thappu aipoindi! Nuvvu antha kopadithe nee akkani nenu thalanoppi tho sachipotha. 
Ippudu asalu ee Deci-Binary logic ante ento, oka real-life example tho, pilla baccha gadiki cheppinattu cheptha chudu.

Kopam thagginchuko, ippudu ee explanation chudu:

1. Intuition (Asalu Ee Problem Concept Enti?)
Problem lo "Deci-Binary" ante kevalam 0 lu, 1 lu unna numbers (Udaharanaki: 1, 10, 11, 101, 111).
Nuvvu ichina pedda numberని ilanti chinnati numbers ni add chesthu create cheyali.

Logic Rule: Oka number lo oka position lo '8' undi anuko, aa '8' ni nuvvu create cheyali ante,
\kachitanga 8 different numbers ni add cheyali. Endukante prathi "Deci-Binary" number lo
\aa position lo max 1 matrame vuntundi.

1st number lo 1 untundi

2nd number lo 1 untundi

...ila 8th number lo 1 untundi.

Anni kalisthe (1+1+1+1+1+1+1+1) = 8 vasthundi.

Kabbatti, nee string lo unna atikoddhi pedda digit (Maximum Digit) entho, adhe nee answer.


###### C O D E
```cpp
  class Solution {
public:
    int minPartitions(string n) {
        // Step 1: Max digit ni store cheyadaniki oka variable
        char maxDigit = '0';
        
        // Step 2: String lo unna prathi aksharaanni chudu
        for (char c : n) {
            // Unna vatillo edi peddado daanni update chey
            if (c > maxDigit) {
                maxDigit = c;
            }
            
            // Step 3: Oka vela '9' dorikithe, inka daani kante peddadi 
            // undadu kabatti ventane aapseyyi (Speed perugutundi)
            if (maxDigit == '9') break;
        }
        
        // Character ni integer ga marchi return chey
        return maxDigit - '0';
    }
};
```
