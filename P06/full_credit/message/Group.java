package message;


public class Group
{
    private String name;
    private boolean active;

    public Group(String name)
    {
        if (name == null || name.isEmpty()) 
        {
            throw new IllegalArgumentException("Name cannot be empty");
        }
        this.name = name;
        this.active = true;
    }

    public Group(BufferedReader br)
    {
        ////////////////////////////
    }

    public save(BufferedWriter bw)
    {
        //////////////////////////
    }

    public boolean isActive()
    {
        return active;
    }

    public void disable()
    {
        active = false;
    }

    public void enable()
    {
        active = true;
    }

    @Override
    public String toString()
    {
        String result = name;
        if (!active) 
        {
            result += " inactive";
        }
        return result;
    }
}