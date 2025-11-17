//With the help of Deepseek

/*
 *FILENAME: 南科大绩点转换器.c
 *PROJECT: Use Grade and Weight to get your GPA
 *AUTHOR: Joey XU <12510226@sustech.edu.cn>
 *DATE CREATED: November 17th,2025
 *LAST MODIFIED: November 17th,2025
 *MODIFIED BY: Joey XU
 */

#include <stdio.h>
#include <math.h>

// 函数声明
double calculate_gpa(double score);
double round_to_two_decimals(double value);

int main() {
    int num_categories;
    double total_score = 0.0;
    double total_weight = 0.0;
    
    printf("=== The GPA of SUSTech Translater ===\n");
    printf("Input the catogeries of grades: ");
    scanf("%d", &num_categories);
    
    // 输入每个类别的成绩和权重
    for (int i = 1; i <= num_categories; i++) {
        double score, weight;
        
        printf("\n--- the%d's categery ---\n", i);
        printf("Input your grade in 100: ");
        scanf("%lf", &score);
        
        printf("Input Weight(in percent e.g. 30 repersent 30%%): ");
        scanf("%lf", &weight);
        
        total_score += score * (weight / 100.0);
        total_weight += weight;
    }
    
    // 检查权重总和是否为100%
    if (fabs(total_weight - 100.0) > 0.01) {
        printf("\nWaring:the total weight is%.2f%%not one hundred%%,Output might be wrong!\n", total_weight);
    }
    
    // 计算绩点
    double gpa = calculate_gpa(total_score);
    
    // 输出结果
    printf("\n=== Output of your GPA ===\n");
    printf("in 100: %.2f\n", total_score);
    printf("GPA in 4: %.2f\n", gpa);
    
    // 显示对应的Grade（可选）
    printf("\nRegarding:\n");
    if (total_score >= 97) printf("Grade: A+ (4.00)\n");
    else if (total_score >= 93) printf("Grade: A (3.94)\n");
    else if (total_score >= 90) printf("Grade: A- (3.85)\n");
    else if (total_score >= 87) printf("Grade: B+ (3.73)\n");
    else if (total_score >= 83) printf("Grade: B (3.55)\n");
    else if (total_score >= 80) printf("Grade: B- (3.32)\n");
    else if (total_score >= 77) printf("Grade: C+ (3.09)\n");
    else if (total_score >= 73) printf("Grade: C (2.78)\n");
    else if (total_score >= 70) printf("Grade: C- (2.42)\n");
    else if (total_score >= 67) printf("Grade: D+ (2.08)\n");
    else if (total_score >= 63) printf("Grade: D (1.63)\n");
    else if (total_score >= 60) printf("Grade: D- (1.15)\n");
    else printf("Grade: F (0.00)\n");
    
    return 0;
}

// 计算绩点的函数
double calculate_gpa(double score) {
    if (score < 60) {
        return 0.0;
    } else {
        double gpa = 4.0 - 3.0 * pow(100.0 - score, 2) / 1600.0;
        return round_to_two_decimals(gpa);
    }
}

// 四舍五入到两位小数的函数
double round_to_two_decimals(double value) {
    return round(value * 100.0) / 100.0;

}
