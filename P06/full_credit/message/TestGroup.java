package message;

public class TestGroup
{
    public static void main(String[] args)
    {
        Group g1 = new Group("Test Group");
        
        System.out.println(g1);

        int passed = 0;
        int failed = 0;
        if (g1.toString().equals("Test Group")) 
        {
            passed++; 
        }
        else 
        { 
            System.out.println("Test Failed: Constructor & toString"); 
            failed++; 
        }
        
        if (g1.isActive()) 
        {
            passed++; 
        }
        else 
        { 
            System.out.println("Test Failed: Group is active by default"); 
            failed++; 
        }

        g1.disable();
        if (!g1.isActive()) 
        {
            passed++; 
        }
        else 
        { 
            System.out.println("Test Failed: disable() makes group inactive"); 
            failed++; 
        }
        
        if (g1.toString().equals("Test Group inactive")) 
        {
            passed++; 
        }
        else 
        { 
            System.out.println("Test Failed: toString() shows inactive"); 
            failed++; 
        }

        g1.enable();
        if (g1.isActive()) 
        {
            passed++; 
        }
        else 
        { 
            System.out.println("Test Failed: enable() makes group active"); 
            failed++; 
        }

        System.out.println("Tests Passed: " + passed);
        System.out.println("Tests Failed: " + failed);
    }
}