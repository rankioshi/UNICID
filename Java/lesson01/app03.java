package aula2202;

import java.util.Scanner;

public class App3 {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    System.out.println("Digite o valor1: ");
    int valor1 = sc.nextInt();
    System.out.println("Digite o valor2: ");
    int valor2 = sc.nextInt();
    int media = (valor1+valor2)/2;
    System.out.println("Media: "+media);

    sc.close();

  }

}
