import java.util.Scanner;


public class Query
{
    public static void main(String[] args)
    {
        if (args.length == 0)
        {
            System.out.println("Available search engines are " + Engines.GEMINI + ", " + Engines.LAMA + ", " + Engines.COPILOT);
            return;
        }

        else if (args.length >= 1)
        {
            Engines engine = Engines.valueOf(args[0].toUpperCase());
            
            System.out.println("Using Engine " + engine);

            AI ai = new AI(engine);

            System.out.println("Ask " + engine + " anything:");

            Scanner scanner = new Scanner(System.in);

            while (scanner.hasNextLine()) 
            {
                String query = scanner.nextLine();
                System.out.println(ai.query(query));
                System.out.println("Ask " + engine + " anything:");

            }

            System.out.println("");
            System.out.println("Your most recent 5 queries were:");
            System.out.println("");
            for (String q : ai.getQueryHistory()) 
            {
                System.out.println(q);
            }
        }
    }
}