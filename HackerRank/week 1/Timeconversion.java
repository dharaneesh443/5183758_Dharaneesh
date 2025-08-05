import java.util.*;
public class TimeConversion {
    public static String timeConversion(String s){
        String period=s.substring(s.length()-2);
        String[] timeparts=s.substring(0,s.length()-2).split(":");
        int hour=Integer.parseInt(timeparts[0]);
        String minute=timeparts[1];
        String second=timeparts[2];
        if(period.equals("AM")){
            if(hour==12){
                hour=0;
            }
        }else{
            if(hour!=12){
                hour +=12;
            }
        }
        return String.format("%02d:%s:%s", hour,minute,second);
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String input=sc.nextLine();
        String output=timeConversion(input);
        System.out.println(output);
    }
}