package utils;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class InputOutput {

    public static final String DATE_FORMAT = "yyyy-MM-dd";

    public static String inputString(String statement) {
        String text = "";
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print(statement);
            text = scanner.nextLine().trim();
        } while (text == null || text.isBlank() || text.isEmpty());
        return text;
    }
    
    public static String inputStringNotRequired(String statement) {
        System.out.print(statement);
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    public static double inputDouble(String statement) {
        double val = 0;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print(statement);
            try {
                val = Double.parseDouble(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Nhap sai so thuc!" + e.getMessage());
            }
        } while (val <= 0);
        return val;
    }

    public static int inputInteger(String statement) {
        int val = 0;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print(statement);
            try {
                val = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Nhap sai so nguyen!" + e.getMessage());
            }
        } while (val <= 0);
        return val;
    }

    public static Date inputDate(String statement) {

        Scanner scanner = new Scanner(System.in);
        Date date = null;
        SimpleDateFormat dateFormat = new SimpleDateFormat(InputOutput.DATE_FORMAT);

        do {
            System.out.print(statement);
            try {
                date = dateFormat.parse(scanner.nextLine().trim());
            } catch (ParseException e) {
                System.out.println("Nhap sai dinh dang ngay! \n" + e.getMessage());
            }
        } while (date == null);
        return date;
    }
    
    public static double formatCurrency(double price) {
       return Math.round(price * 100) / 100;
    }
}
