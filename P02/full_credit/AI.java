public class AI
{
    private Engines engine;
    private String[] queries;
    
    public AI(Engines engine)
    {
        this.engine = engine;
        this.queries = new String[5];
    }


    public String query(String query) 
    {
        for (int i = 4; i > 0; i--) 
        {
            queries[i] = queries[i - 1];
        }

        queries[0] = query;
        return "that's a puzzler!";
    }


    public String[] getQueryHistory() 
    {
        return queries;
    }
}



