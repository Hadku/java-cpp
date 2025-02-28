package account;

public class Account
{
    private String name;

    private int id;

    private static int nextID = 1;

    private AccountStatus status;

    public Account(String name)
    {
        if (name == null || name.length() == 0)
        {
            throw new IllegalArgumentException("Name cannot be empty");
        }
        this.name = name;
        this.id = nextID++;
        this.status = AccountStatus.Normal;
    }

    public Account(BufferedReader br)
    {
        /////////////////////////
    }

    public save(BufferedWriter bw)
    {
        /////////////////////
    }

    public void setStatus(AccountStatus status)
    {
        this.status = status;
    }

    public Boolean isMuted()
    {
        return status != AccountStatus.Normal;
    }

    public Boolean isBlocked()
    {
        return status == AccountStatus.Blocked;
    }

    public String toString()
    {
        if (status == AccountStatus.Normal) 
        {
            return name + " (" + id + ")";
        } 
        else 
        {
            return name + " (" + id + ") [" + status + "]";
        }
    }
}
