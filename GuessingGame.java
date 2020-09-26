import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class Main {


    public static void spider(){
       Scanner scnr = new Scanner(System.in);

        String spider = " ||  ||  \n" +
                " \\\\()// \n" +
                "//(__)\\\\\n" +
                "||    ||";

        String spiderAnswer = "spider";
        String guess = "";

        System.out.println(spider);
        System.out.println("ok! what kind of animal is this?");

        while(!guess.equals(spiderAnswer)){

            System.out.println("Try to guess:");
            guess = scnr.nextLine();
        }

        System.out.println("Yes that's right! Its a spider!");

    }

    public static void fish(){
        Scanner scnr = new Scanner(System.in);

        String fish = "     /\"*._         _\n" +
                "      .-*'`    `*-.._.-'/\n" +
                "    < * ))     ,       ( \n" +
                "      `*-._`._(__.--*\"`.\\";

        String fishAnswer = "fish";
        String guess = "";

        System.out.println(fish);
        System.out.println("ok! what kind of animal is this?");

        while(!guess.equals(fishAnswer)){

            System.out.println("Try to guess:");
            guess = scnr.nextLine();
        }

        System.out.println("Yes that's right! Its a fish!");

    }

    public static void bird(){
        Scanner scnr = new Scanner(System.in);

        String bird = "   \\\\\n" +
                "   (o>\n" +
                "\\\\_//)\n" +
                " \\_/_)\n" +
                "  _|_";

        String birdAnswer = "bird";
        String guess = "";

        System.out.println(bird);
        System.out.println("ok! what kind of animal is this?");

        while(!guess.equals(birdAnswer)){

            System.out.println("Try to guess:");
            guess = scnr.nextLine();
        }

        System.out.println("Yes that's right! Its a bird!");
    }

    public static void dog(){
        Scanner scnr = new Scanner(System.in);

        String dog = "          __\n" +
                " \\ ______/ V`-,\n" +
                "  }        /~~\n" +
                " /_)^ --,r'\n" +
                "|b      |b";

        String dogAnswer = "dog";
        String guess = "";

        System.out.println(dog);
        System.out.println("ok! what kind of animal is this?");

        while(!guess.equals(dogAnswer)){

            System.out.println("Try to guess:");
            guess = scnr.nextLine();
        }

        System.out.println("Yes that's right! It's a dog!");
    }

    public static void cat(){
        Scanner scnr = new Scanner(System.in);

        String cat = "   |\\---/|  \n" +
                "   | ,_, |\n" +
                "    \\_`_/-..----.\n" +
                " ___/ `   ' ,\"\"+ \\  \n" +
                "(__...'   __\\    |`.___.';\n" +
                "  (_,...'(_,.`__)/'.....+";

        String catAnswer = "cat";
        String guess = "";

        System.out.println(cat);
        System.out.println("ok! what kind of animal is this?");

        while(!guess.equals(catAnswer)){

            System.out.println("Try to guess:");
            guess = scnr.nextLine();
        }

        System.out.println("Yes that's right! Its a cat!");
    }

    public static void randomGame(){
        int randomNum = ThreadLocalRandom.current().nextInt(1, 5 + 1);

        if(randomNum == 1){
            cat();
        }
        if(randomNum == 2){
            dog();
        }
        if(randomNum == 3){
            bird();
        }
        if(randomNum == 4){
            fish();
        }
        if(randomNum == 5){
            spider();
        }

    }

    public static void replay(){
        Scanner scnr = new Scanner(System.in);

        String playAgain = "";

        System.out.println("Would you like to play again? [yes/no]:");
        playAgain = scnr.nextLine();

        while(playAgain.equals("yes")){
            randomGame();
            replay();
        }
        System.out.println("Ok, maybe next time!");
        System.exit(1);
    }


    public static void game(){

        Scanner scnr = new Scanner(System.in);

        String answer;

        System.out.println("Hello! Would you like to play a game? [yes/no]");
        answer = scnr.nextLine();

        if(answer.equals("no")){
            System.out.print("Ok, maybe next time!");
        }

        if(answer.equals("yes")){
           randomGame();
           replay();
        }


    }

    public static void main(String[] args) {
	game();


    }
}
