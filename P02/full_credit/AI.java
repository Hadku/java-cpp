public class AI
{
    //-engine : engine
    //-queries : String[]
    private Engines engine;
    private String[] queries;
    
    //+All(engine : Engine)
    public AI(Engines engine)
    {
        this.engine = engine;
        this.queries = new String[5];
    }

    //+query(query : String) : String

    public String query(String query) 
    {
        //System.arraycopy(queries, 0, queries, 1, 4);
        for (int i = 4; i > 0; i--) 
        {
            queries[i] = queries[i - 1];
        }

        queries[0] = query;
        return "that's a puzzler!";
    }


    //+getQueryHistory() : String[]
    public String[] getQueryHistory() 
    {
        return queries;
    }
}



