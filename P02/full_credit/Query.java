import java.util.Scanner;


public class Query
{
    // +main(args : String[])
    public static void main(String[] args)
    {
        if (args.length == 0)
        {
            // List available AI engines
            println("Available search engines are " + Engines.KOMO + ", " + Engines.PHIND + ", " + Engines.BRAVE);
            
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
                /*String question = scanner.nextLine();
                System.out.println(ai.query(question));*/
                String query = scanner.nextLine();
                System.out.println(ai.query(query));
                System.out.println("Ask " + engine + " anything:");

            }

            /*String[] history = ai.getQueryHistory();
            for (String query : history) 
            {
                if (query != null) 
                {
                    System.out.println(query);
                }
            }*/

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