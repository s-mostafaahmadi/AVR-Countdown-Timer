#include <mega32.h>
#include <alcd.h>
#include <delay.h>

flash char Pattern[4] = {0xFE, 0xFD, 0xFB, 0xF7};
flash unsigned char bcd_decoder [11]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0xED, 0x7D, 0x07, 0x7F, 0x6F, 0x80};
flash char key_number [4][4]={'7', '8', '9', '/',
                              '4', '5', '6', '*',
                              '1', '2', '3', '-',
                              'C', '0', '=', '+'};                                
char Keypressed(void);
void appenddigit(char);
int convert(char);
void seven_seg_show(void);
void seven_seg_clear(void);

char digit_Enter[4];
int a=0;
  
void main(void)
{   char ch;
    
    //keypad    
    DDRB.0=1,DDRB.1=1,DDRB.2=1,DDRB.3=1;
    DDRB.4=0,DDRB.5=0,DDRB.6=0,DDRB.7=0;
    PORTB.4=1,PORTB.5=1,PORTB.6=1,PORTB.7=1;

    //7-seg    
    DDRD.1 = 1,DDRD.2 = 1,DDRD.3 = 1,DDRD.4 = 1;
    PORTD.1 = 1,PORTD.2 = 1,PORTD.3 = 1,PORTD.4 = 1;
    DDRC=0xFF;
    PORTC = bcd_decoder[0];
    

    lcd_init(16);
    
    while (1)
    {
     ch = Keypressed();
     if (ch)
         if (ch == '=')
            {
            seven_seg_show();
            }
        else{
         if (ch != 'C')
             {
             appenddigit(ch);
             lcd_putchar(ch);
             }
         else
             //digit_Enter
             {lcd_clear();
              seven_seg_clear();}}

      }
}

void appenddigit(char c)
{
digit_Enter[a]=c;
a++;
}
char Keypressed(void)
{
   int row, column = 4;
   
   for (row = 0; row <4; row++)
   {
       PORTB = Pattern[row];        

       if(PINB.4 == 0)
       {
          column = 3;
          break;
       }
       else
       {
           if(PINB.5 == 0)
           {
              column = 2;
              break;
           }
           else
           {
               if(PINB.6 == 0)
               {
                  column = 1;
                  break;
               }
               else
               {
                   if(PINB.7 == 0)
                   {
                      column = 0;
                      break;
                   }
               }
           }
       
       }
   }
   
   if (column != 4)
   {
       while (PINB.4 == 0) {};
       while (PINB.5 == 0) {};
       while (PINB.6 == 0) {};
       while (PINB.7 == 0) {};
       return key_number[row][column];
   }
   else
       return 0;

}
void seven_seg_show(void)
{
    int a=0,b=0,c=0,d=0;
    int sec=0;
    
//convet char to int and recognition empty    
    a=convert(digit_Enter[0]);
    b=convert(digit_Enter[1]);
    c=convert(digit_Enter[2]);
    d=convert(digit_Enter[3]);
    

//if low bit = empty(N) -> numbers shift right    
     while(d=='N')
     {
        d=c;c=b;b=a;a=0;
     }
     if(c>5)
     {  
        lcd_clear();  
        lcd_puts("Invalid");
        delay_ms(800);
        lcd_clear();  
        lcd_puts("Editing...");
        delay_ms(800);
        c=6;
        d=0;
     }
     lcd_clear();
     lcd_puts("Runnig...");       
        
    while (1)
    {
        if(d!=0 && sec==47){d--;sec=0;}

        if(c!=0 && d==0){c--;d=9;}
        
        if(b!=0 && c==0 && d==0){b--;c=6;}

        if(a!=0 &&  c==0 && b==0 && d==0){a--;b=10;}
        
        sec=sec+1;
        if(sec>47)sec=0;//code nejat ram

         ///////////////////Show 7-Seg////////////////
         PORTD.1=0;
         PORTC=bcd_decoder[a];
         delay_ms(5);
         PORTD.1=1;
//----------------------
         PORTD.2=0;
         PORTC=bcd_decoder[b];
         delay_ms(5);
         PORTD.2=1;
//----------------------
         PORTD.3=0;
         PORTC=bcd_decoder[c];
         delay_ms(5);
         PORTD.3=1;
//----------------------
         PORTD.4=0;
         PORTC=bcd_decoder[d];
         delay_ms(5);
         PORTD.4=1;    
    }
}
int convert(char a)
    {
        switch (a) {
        case '1':
              return 1;
        break;
        case '2':
              return 2;
        break;
        case '3':
              return 3;
        break;
        case '4':
              return 4;
        break;
        case '5':
              return 5;
        break;
        case '6':
              return 6;
        break;
        case '7':
              return 7;
        break;
        case '8':
              return 8;
        break;
        case '9':
              return 9;
        break;
        case '0':
              return 0;
        break;   
        default:
              return 'N'; //Empty
    }
}
void  seven_seg_clear()
{int i;
for(i = 0; i < 4; i++)
    digit_Enter[i] = 0; //all digit=0
    
a=0;  //pointer on digit0
} 
