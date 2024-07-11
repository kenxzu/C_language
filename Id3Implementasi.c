//not finished yet//

#include <stdio.h>
#include <math.h>


double hitungEntropy(double positive, double negatif);
double ParentEntropy(double positive, double negatif);


// Function to calculate information gain
double hitungGain2Nilai(double parentEntropy, double positiveProbLeft, double negativeProbLeft, double positiveProbRight, double negativeProbRight);
double hitungGain3Nilai(double parentEntropy, double positiveBaik, double negativeBaik, double positiveCukup, double negativeCukup, double positiveKurang, double negativeKurang);
int main() {
    double positiveProb = 0.6;  // Probability of a positive class
    double negativeProb = 0.4;  // Probability of a negative class
    double parentEntropy = ParentEntropy(positiveProb, negativeProb);

    // Attribute "Pendidikan"
    double positiveS1 = 0.2;  // Probability of a positive class for "S1"
    double negativeS1 = 0.2;  // Probability of a negative class for "S1"
    double positiveD3 = 0.4;  // Probability of a positive class for "D3"
    double negativeD3 = 0.2;  // Probability of a negative class for "D3"
    double infoGainPendidikan = hitungGain2Nilai(parentEntropy, positiveS1, negativeS1, positiveD3, negativeD3);
    double entropyd3 = hitungEntropy(positiveD3, negativeD3);
    
    
    // Attribute "Pengalaman"
    double positiveBaik = 0.3;  // Probability of a positive class for "Baik"
    double negativeBaik = 0.0;  // Probability of a negative class for "Baik"
    double positiveKurang = 0.3;  // Probability of a positive class for "Kurang"
    double negativeKurang = 0.4;  // Probability of a negative class for "Kurang"
    double infoGainPengalaman = hitungGain2Nilai(parentEntropy, positiveKurang, negativeKurang, positiveBaik, negativeBaik);
    
    
    // Attribute Tes bakat
    double positiveBbakat = 0.4;  // Probability of a positive class for "Baik"
    double negativeBbakat = 0.0;  // Probability of a negative class for "Baik"
    double positiveCbakat = 0.2;  // Probability of a positive class for "Cukup"
    double negativeCbakat = 0.3;  // Probability of a positive class for "Cukup"
    double positiveKbakat = 0.0;  // Probability of a positive class for "Kurang"
    double negativeKbakat = 0.1;  // Probability of a negative class for "Kurang"
    double infoGainTesBakat = hitungGain3Nilai(parentEntropy, positiveBbakat, negativeBbakat, positiveCbakat, negativeCbakat, positiveKbakat, negativeKbakat);

// Attribute Wawancara
    double positiveBwancara = 0.4;  // Probability of a positive class for "Baik"
    double negativeBwancara = 0.0;  // Probability of a negative class for "Baik"
    double positiveCwancara = 0.2;  // Probability of a positive class for "Cukup"
    double negativeCwancara = 0.2;  // Probability of a positive class for "Cukup"
    double positiveKwancara = 0.0;  // Probability of a positive class for "Kurang"
    double negativeKwancara = 0.2;  // Probability of a negative class for "Kurang"
    double infoGainWancara = hitungGain3Nilai(parentEntropy, positiveBwancara, negativeBwancara, positiveCwancara, negativeCwancara, positiveKwancara, negativeKwancara);
   
    printf("Parent Entropy : %lf\n", parentEntropy);
    printf("Gain Pendidikan : %lf\n", infoGainPendidikan);
    printf("Gain Pengalaman : %lf\n", infoGainPengalaman);
    printf("Gain Tes Bakat : %lf\n", infoGainTesBakat);
    printf("Gain wawancara : %lf\n", infoGainWancara);
    printf("entropyD3 = %lf", entropyd3);

    
    return 0;
}

//entropy sampel penerimaan karyawana
double ParentEntropy(double positif, double negatif){
        // Ensure probabilities sum to 1
    double sum = positif + negatif;
    if (sum != 1) {
        printf("Probabilities should sum to 1, but the sum is %lf.\n", sum);
    }

    // Avoid log(0) by checking if probabilities are 0
    if (positif == 0 || negatif == 0) {
        return 0.0; // Entropy is 0 if one of the probabilities is 0
    }
   double TotalSample = 1;
    // Calculate entropy
    double entropy = (-positif/TotalSample * log2(positif/TotalSample)) + (- negatif/TotalSample * log2(negatif/TotalSample));
    return entropy;
}

// Function to calculate entropy
double hitungEntropy(double positifL, double negatifL) {
   double difider = positifL + negatifL; 
   if (positifL == 0.0|| negatifL == 0.0)
    {
        return 0.0;
    } else{
    
    double entropy = (-(positifL/difider) * log2(positifL/difider)) + (-negatifL/difider * log2(negatifL/difider));
    
    return entropy;
    }

}


double hitungGain2Nilai(double parentEntropy, double positiveProbLeft, double negativeProbLeft, double positiveProbRight, double negativeProbRight) {
    double entropyLeft = hitungEntropy(positiveProbLeft, negativeProbLeft);
    double entropyRight = hitungEntropy(positiveProbRight, negativeProbRight);

    // int totalExamples = (positiveProbLeft + negativeProbLeft) + (positiveProbRight + negativeProbRight);
    double totalExamples = 1;
    
    double infoGain = parentEntropy - (entropyLeft * ((positiveProbLeft + negativeProbLeft)/totalExamples)) - (entropyRight * ((positiveProbRight + negativeProbRight)/totalExamples));

    return infoGain;
}

double hitungGain3Nilai(double parentEntropy, double positiveBaik, double negativeBaik, double positiveCukup, double negativeCukup, double positiveKurang, double negativeKurang) {
    double entropyLeft = hitungEntropy(positiveBaik, negativeBaik);
    double entropyMiddle = hitungEntropy(positiveCukup, negativeCukup);
    double entropyRight = hitungEntropy(positiveKurang, negativeKurang);

    double totalExamples = positiveBaik + negativeBaik + positiveCukup + negativeCukup + positiveKurang + negativeKurang;

    double infoGain = parentEntropy - ((entropyLeft * ((positiveBaik + negativeBaik) / totalExamples)) + (entropyMiddle * ((positiveCukup + negativeCukup) / totalExamples)) + (entropyRight * ((positiveKurang + negativeKurang) / totalExamples)));

    return infoGain;
}



// double hitungGain3Nilai(double parentEntropy, double positiveBaik, double negativeBaik, double positiveCukup, double negativeCukup, double positiveKurang, double negativeKurang){
//   double entropyLeft = hitungEntropy(positiveBaik, negativeBaik);
//     double entropyMiddle = hitungEntropy(positiveCukup, negativeCukup);
//     double entropyRight = hitungEntropy(positiveKurang, negativeKurang);

//   //  int totalExamples = (positiveBaik + negativeBaik) + (positiveProbRight + negativeProbRight);
//     double totalExamples = 1;


//     double infoGain = parentEntropy - ((entropyLeft * (positiveBaik + negativeBaik/totalExamples)) - (entropyMiddle * (positiveCukup + negativeCukup/totalExamples)) - (entropyRight * (positiveKurang + negativeKurang/totalExamples)));

//     return infoGain;
// }