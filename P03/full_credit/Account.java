public class Account
{
    //-name : String
    private String name;

    //-id : int
    private int id;

    //-nextID : int
    private static int nextID = 1;

    //-status : AccountStatus
    private AccountStatus status;

    //+Account(name : String)
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

    //+setStatus(status : AccountStatus)
    public void setStatus(AccountStatus status)
    {
        this.status = status;
    }

    //+isMuted() : Boolean
    public Boolean isMuted()
    {
        return status != AccountStatus.Normal;
    }

    //+isBlocked() : Boolean
    public Boolean isBlocked()
    {
        return status == AccountStatus.Blocked;
    }

    //+toString() : String <<overide>>
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
