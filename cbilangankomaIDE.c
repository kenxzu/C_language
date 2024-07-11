#include <stdio.h>
#include <math.h>


#define EPSILON 1e-9
double hitungEntropy(double positive, double negatif);
double ParentEntropy(double positive, double negatif);


// Function to calculate information gain
double hitungGain2Nilai(double parentEntropy, double positiveProbLeft, double negativeProbLeft, double positiveProbRight, double negativeProbRight);
double hitungGain3Nilai(double parentEntropy, double positiveBaik, double negativeBaik, double positiveCukup, double negativeCukup, double positiveKurang, double negativeKurang);
int main() {
    double positiveProb = 6;  // Probability of a positive class
    double negativeProb = 4;  // Probability of a negative class
    double parentEntropy = ParentEntropy(positiveProb, negativeProb);

    // Attribute "Pendidikan"
    double positiveS1 = 2;  // Probability of a positive class for "S1"
    double negativeS1 = 2;  // Probability of a negative class for "S1"
    double positiveD3 = 4;  // Probability of a positive class for "D3"
    double negativeD3 = 2;  // Probability of a negative class for "D3"
    double infoGainPendidikan = hitungGain2Nilai(parentEntropy, positiveS1, negativeS1, positiveD3, negativeD3);
    double entropyd3 = hitungEntropy(positiveD3, negativeD3);
    
    
    // Attribute "Pengalaman"
    double positiveBaik = 3;  // Probability of a positive class for "Baik"
    double negativeBaik = 0;  // Probability of a negative class for "Baik"
    double positiveKurang = 3;  // Probability of a positive class for "Kurang"
    double negativeKurang = 4;  // Probability of a negative class for "Kurang"
    double infoGainPengalaman = hitungGain2Nilai(parentEntropy, positiveKurang, negativeKurang, positiveBaik, negativeBaik);
    
    
    // Attribute Tes bakat
    double positiveBbakat = 4;  // Probability of a positive class for "Baik"
    double negativeBbakat = 0;  // Probability of a negative class for "Baik"
    double positiveCbakat = 2;  // Probability of a positive class for "Cukup"
    double negativeCbakat = 3;  // Probability of a positive class for "Cukup"
    double positiveKbakat = 0;  // Probability of a positive class for "Kurang"
    double negativeKbakat = 1;  // Probability of a negative class for "Kurang"
    double infoGainTesBakat = hitungGain3Nilai(parentEntropy, positiveBbakat, negativeBbakat, positiveCbakat, negativeCbakat, positiveKbakat, negativeKbakat);

// Attribute Wawancara
    double positiveBwancara = 4;  // Probability of a positive class for "Baik"
    double negativeBwancara = 0;  // Probability of a negative class for "Baik"
    double positiveCwancara = 2;  // Probability of a positive class for "Cukup"
    double negativeCwancara = 2;  // Probability of a positive class for "Cukup"
    double positiveKwancara = 0;  // Probability of a positive class for "Kurang"
    double negativeKwancara = 2;  // Probability of a negative class for "Kurang"
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

   double TotalSample = 10;
    // Calculate entropy
    double entropy = ((-positif/TotalSample) * log2(positif/TotalSample)) + ((- negatif/TotalSample) * log2(negatif/TotalSample));
    return entropy;
}

// Function to calculate entropy
double hitungEntropy(double positifL, double negatifL) {


    
   double difider = positifL + negatifL; 

   if (positifL > EPSILON && negatifL > EPSILON) {
    // Hitung logaritma jika probabilitas positif dan negatif valid
    double log_positif = log2(positifL);
    double log_negatif = log2(negatifL);

    // Lanjutkan perhitungan entropi
    double entropy = ((-positifL/difider) * log_positif) + ((-negatifL/difider) * log_negatif);
    
    return entropy;
} else {
    // Handle kasus ketika probabilitas tidak valid
    // Misalnya, berikan nilai default atau tangani secara khusus
    // Misalnya, return -1 atau lainnya.
    return -1;
}
}


double hitungGain2Nilai(double parentEntropy, double positiveProbLeft, double negativeProbLeft, double positiveProbRight, double negativeProbRight) {
    double entropyLeft = hitungEntropy(positiveProbLeft, negativeProbLeft);
    double entropyRight = hitungEntropy(positiveProbRight, negativeProbRight);

    // int totalExamples = (positiveProbLeft + negativeProbLeft) + (positiveProbRight + negativeProbRight);
    double totalExamples = 10;
    
    double infoGain = parentEntropy - (entropyLeft * ((positiveProbLeft + negativeProbLeft)/totalExamples)) - (entropyRight * ((positiveProbRight + negativeProbRight)/totalExamples));

    return infoGain;
}

double hitungGain3Nilai(double parentEntropy, double positiveBaik, double negativeBaik, double positiveCukup, double negativeCukup, double positiveKurang, double negativeKurang){
  double entropyLeft = hitungEntropy(positiveBaik, negativeBaik);
    double entropyMiddle = hitungEntropy(positiveCukup, negativeCukup);
    double entropyRight = hitungEntropy(positiveKurang, negativeKurang);

  //  int totalExamples = (positiveBaik + negativeBaik) + (positiveProbRight + negativeProbRight);

    double totalExamples = 10;


    double infoGain = parentEntropy - ((entropyLeft * (positiveBaik + negativeBaik/totalExamples)) - (entropyMiddle * (positiveCukup + negativeCukup/totalExamples)) - (entropyRight * (positiveKurang + negativeKurang/totalExamples)));

    return infoGain;
}

