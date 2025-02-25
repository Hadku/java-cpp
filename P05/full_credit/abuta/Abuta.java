package abuta;

import message.DirectMessage;
import account.Account;
import message.Group;
import message.Message;
import message.Post;
import menu.Menu;
import menu.MenuItem;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Abuta 
{
    private Account[] accounts;
    private Group[] groups;
    private Message message;
    private Menu menu;
    private String output;
    private boolean running;

    public Abuta() 
    {

        accounts = new Account[5];  
        groups = new Group[5];      

        accounts[0] = new Account("Hadi");
        accounts[1] = new Account("Lad");
        accounts[2] = new Account("Angelo");
        accounts[3] = new Account("Jinwoo");
        accounts[4] = new Account("Kabuto");

        groups[0] = new Group("Class member");
        groups[1] = new Group("lvl 100 boss");
        groups[2] = new Group("Mafia");
        groups[3] = new Group("Martial arts");
        groups[4] = new Group("Ninja");



        message = new Post(accounts[0], groups[0], null, "Welcome  to  a b U T A");

        menu = new Menu();

        menu.addMenuItem(new MenuItem("Exit", () -> endApp()));
        menu.addMenuItem(new MenuItem("Show Reply", () -> showReply()));
        menu.addMenuItem(new MenuItem("Show Replied To", () -> showRepliedTo()));
        menu.addMenuItem(new MenuItem("Add Reply", () -> reply()));




        output = "";
        running = true;
    }

    public void mdi() 
    {
        while (running) 
        {
            System.out.println("\n                                  - = # a b U T A # = -");
            System.out.println(message);
            System.out.println("\n" + output);
            output = "";
            System.out.println("\nMenu:");
            System.out.println(menu);
            
            int choice = Menu.getInt("Selection: ");
            menu.run(choice);
        }
    }

    private void endApp() 
    {
        running = false;
    }

    private void showRepliedTo() 
    {
        if (message.getRepliedTo() == null) 
        {
            output = "No reply";
        } 
        else 
        {
            message = message.getRepliedTo();
        }
    }

    private void showReply() 
    {
        if (message == null) 
        {
            output = "No message selected";
            return;
        }

        int index = Menu.getInt("enter reply: ");
        
        Message reply = message.getReply(index);
        if (reply != null) 
        {
            message = reply;
            output = "Reply selected successfully.";
        } 
        else 
        {
            output = "Invalid selection or no replies available.";
        }

    }




    private void reply() 
    {
        String body = Menu.getString("Enter reply: ");
        
        int authorIndex = Menu.selectItemFromList("Author? ", Arrays.asList(accounts));
        Account author = accounts[authorIndex];

        boolean isPost = Menu.getChar("Reply as a post (p) or direct message (d)? ") == 'p';

        Message newMessage;
        if (isPost) 
        {
            int groupIndex = Menu.selectItemFromList("Group? ", Arrays.asList(groups));
            Group group = groups[groupIndex];
            newMessage = new Post(author, group, message, body);
        } 
        else 
        {
            int recipientIndex = Menu.selectItemFromList("To? ", Arrays.asList(accounts));
            Account recipient = accounts[recipientIndex];
            newMessage = new DirectMessage(author, recipient, message, body);
        }

        message = newMessage;  
        output = "Reply added!";
    }

    public static void main(String[] args) 
    {
        new Abuta().mdi();
    }
}

