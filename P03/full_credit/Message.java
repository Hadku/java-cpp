import java.util.ArrayList;
import java.util.Date;


public class Message
{
    //-from : Account
    private Account from;
    
    //-date : Date
    private Date date;
    
    //-repliedTo : Message
    private Message repliedTo;
    
    //-replies : Message[] <<ArrayList>>
    private ArrayList<Message> replies;

    //-body : String
    private String body;

    //+Message(from : Account, repliedTo : Message, body : String)
    public Message(Account from, Message repliedTo, String body)
    {
        this.from = from;
        this.repliedTo = repliedTo;
        this.body = body;
        this.replies = new ArrayList<>();
        if (repliedTo != null) 
        {
            repliedTo.addReply(this);
        }
    }

    //+getRepliedTo() : Message
    public Message getRepliedTo()
    {
        return repliedTo;
    }
    
    //+getReply(index : int) : Message
    public Message getReply(int index)
    {
        if (index < 0 || index >= replies.size()) 
        {
            return null;
        }
        return replies.get(index);
    }

    //+toString() : String <<overide>>
    @Override
    public String toString()
    {

        System.out.println("Date: " + date);
        System.out.println("From: " + from.toString());

        if (repliedTo != null) 
        {
            System.out.println("In reply to: " + repliedTo.from.toString());
        }

        if (!replies.isEmpty()) 
        {
            System.out.println("Replies: ");
            for (int i = 0; i < replies.size(); i++) 
            {
                System.out.println(replies.get(i).from.toString());
                if (i < replies.size() - 1) 
                {
                    System.out.println(", ");
                }
            }
            System.out.println("\n");
        }

        System.out.println("\n" + body);

        return repliedTo.toString();

    }

    //-addReply(message : Message)
    private void addReply(Message message)
    {
        repliedTo.addReply(message);
    }
}
