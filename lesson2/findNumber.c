#include<stdio.h>
#include <stdlib.h>
#include <time.h>  

int main()
{
    srand(time(NULL));
    // Generate a random 4-digit number between 1000 and 9999
    int otp = (rand() % 9000) + 1000;
    //found bol hervee utasnii dugaar zov baigaad provider oldsol bol found utga 1 baina ugui buyu utasnii dugaar buruu bol found ni 0 baina
    int dugaar, provider, verify,found=0;
    printf("Ta utasnii dugaaraa oruulna uu: ");
    scanf("%d",&dugaar);
    provider=dugaar/1000000;
    if(provider==88 || provider==89 || provider==86)
    {
        printf("Unitel\n");  
        printf("OTP: %d Sent to your mobile number\n",otp);
        found=1;
    }
    else if(provider==99 || provider==95 || provider==94 || provider==85)
    {
        printf("Mobicom\n");
        printf("OTP: %d Sent to your mobile number\n",otp);
        found=1;
    }
    else if(provider==91 || provider==96 || provider==90)
    {
        printf("Skytel\n");
        printf("OTP: %d Sent to your mobile number\n",otp);
        found=1;
    }
    else   
         printf("Tanii dugaar buruu baina!\n");

    //hervee utasnii dugaar oldson bol ene notshol shalgalt hiij OTP verify hiine.
    if(found==1)
    {
        printf("OTP Verify: ");
        scanf("%d",&verify);

        if(verify==otp)
            printf("Ta amjilttai nevterlee!\n");
        else
            printf("OTP buruu baina!");
    }

}