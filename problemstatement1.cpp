/*i have done everything except the bonus part of the level 3 of which i have few ideas about
but to implement them ill need some time and also i feel ill need to study cpp more so as of now
this is my final program.*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;
unordered_set<string> dictionary;

double alp[26]={0.08167,0.01492,0.02782,0.04253,0.12702,0.02228,0.02015,0.06094,0.06966,
    0.00153,0.00772,0.04025,0.02406,0.06749,0.07507,0.01929,0.00095,0.05987,0.06327,0.09056,0.02758,
    0.00978,0.02360,0.00150,0.01974,0.00074};

void loadDictionary(const string& filename) 
{
    ifstream file(filename);
    if (file.is_open()) 
    {
        string word;
        while (getline(file, word)) 
        {
            for (auto &c : word) c = tolower(c); 
            dictionary.insert(word);
        }
        file.close();
    } 
    else 
    {
        cout << "Error: Could not open dictionary file." << endl;
    }
}

bool check(const string& s) 
{
    string lower = s;
    for (auto &c : lower) 
    c = tolower(c);
    return dictionary.count(lower) > 0;
}

int countTokens(string original_s)
{
    int f=0;
    stringstream ss(original_s);
    string token;
    vector<std::string> tokens;
    while (std::getline(ss, token, ' ')) 
        tokens.push_back(token);
    for (const auto& t : tokens)
    f++;
    return f;
}

void StringTokenizer(string text[], string original_s) 
{
    stringstream ss(original_s);
    string token;
    int i=0;
    vector<std::string> tokens;
    while (std::getline(ss, token, ' ')) 
        tokens.push_back(token);
    for (const auto& t : tokens)
        text[i++]=t;
}

char decode_char(char char_s, int shift_value)
{
    int value=(int)char_s;
    if(value>=65 && value<=90)
        {
            if((value-shift_value)>=65)
                char_s=(char)(value-shift_value);
            else
            {
                value=26+value-shift_value;
                char_s=(int)value;
            }    
        }
        if(value>=97 && value<=122)
        {
            if((value-shift_value)>=97)
                char_s=(char)(value-shift_value);
            else
            {
                value=26+value-shift_value;
                char_s=(int)value;
            }    
        }
        return char_s;
}

char encode_char(char char_s, int shift_value)
{
    int value=(int)char_s;
    if(char_s>=65 && char_s<=90)
        {
            value=(int)char_s;
            if((value+shift_value)<=90)
                char_s=(char)(value+shift_value);
            else
            {
                value=value+shift_value-26;
                char_s=(int)value;
            }    
        }
        if(char_s>=97 && char_s<=122)
        {
            value=(int)char_s;
            if((value+shift_value)<=122)
                char_s=(char)(value+shift_value);
            else
            {
                value=value+shift_value-26;
                char_s=(int)value;
            }    
        }
        return char_s;
}

string encode(string original_s, int shift_value)
{
    string encoded_s=original_s;
    shift_value=(shift_value)%26;
    char char_s;
    int length_s=original_s.length(),value;
    for(int i=0; i<length_s; i++)
    {
        char_s=original_s[i];
        if(char_s>=65 && char_s<=90)
        {
            value=(int)char_s;
            if((value+shift_value)<=90)
                char_s=(char)(value+shift_value);
            else
            {
                value=value+shift_value-26;
                char_s=(int)value;
            }    
        }
        if(char_s>=97 && char_s<=122)
        {
            value=(int)char_s;
            if((value+shift_value)<=122)
                char_s=(char)(value+shift_value);
            else
            {
                value=value+shift_value-26;
                char_s=(int)value;
            }    
        }
        encoded_s[i]=char_s;
    }
    return encoded_s;
}

string decode(string original_s, int shift_value)
{
    string decoded_s=original_s;
    shift_value=(shift_value)%26;
    char char_s;
    int length_s=original_s.length(),value;
    for(int i=0; i<length_s; i++)
    {
        char_s=original_s[i];
        value=(int)char_s;
        if(value>=65 && value<=90)
        {
            if((value-shift_value)>=65)
                char_s=(char)(value-shift_value);
            else
            {
                value=26+value-shift_value;
                char_s=(int)value;
            }    
        }
        if(value>=97 && value<=122)
        {
            if((value-shift_value)>=97)
                char_s=(char)(value-shift_value);
            else
            {
                value=26+value-shift_value;
                char_s=(int)value;
            }    
        }
        decoded_s[i]=char_s;
    }
    return decoded_s;
}

void decode_new(string original_s)
{
    string decoded_s=original_s,s;
    int f=0,size,t;
    int lol[26];
    string lol2[26];
    double score=0.0;
    char char_s;
    int length_s=original_s.length(),value,length;
    size=countTokens(original_s);
    string text[size];
    if(size>=4)
    {
        for(int a=0; a<26; a++)
        {
            f=0;
            score=0.0;
            string original_s1=encode(original_s,a);
            StringTokenizer(text,original_s1);
            for(int i=0; i<size; i++)
            {   
                s=text[i];
                length=s.length();
                for(int j=0; j<length; j++)
                {
                    char_s=s[j];
                    value=(int)char_s;
                    for(int k=65; k<=90; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-65];
                            f++;
                        }
                    }
                    for(int k=97; k<=122; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-97];
                            f++;
                        }
                    }
                }
             }
            cout<<original_s1<<" SCORE = "<<score<<'/'<<f<<endl;
            lol[a]=score;
            lol2[a]=original_s1;
        }
        for(int i=0;i<26;i++)
        {
            if(i==0)
            t=i;
            else if(lol[i]>lol[t])
            t=i;
        }
        cout<<"Engligh string = "<<lol2[t]<<endl;
    }
    else
    {
        for(int a=0; a<26; a++)
        {
            score=0.0;
            string original_s1=encode(original_s,a),s,s1;
            StringTokenizer(text,original_s1);
            s=text[0];
            if(size>=2)
            s1=text[1];
            int length=s.length();
            for(int i=0; i<length; i++)
            {
                char c=s[i];
                s[i]=tolower(c);
            }
            if(size==1)
            {
                length=s.length();
                for(int j=0; j<length; j++)
                {
                    char_s=s[j];
                    value=(int)char_s;
                    for(int k=65; k<=90; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-65];
                        }
                    }
                    for(int k=97; k<=122; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-97];
                        }
                    }
                }
                if(check(s))
                cout<<"English String = "<<original_s1<<endl;
                else
                cout<<"Not English String = "<<original_s1<<" With Score = "<<score<<endl;
            }
            else
            {
                length=s.length();
                for(int j=0; j<length; j++)
                {
                    char_s=s[j];
                    value=(int)char_s;
                    for(int k=65; k<=90; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-65];
                        }
                    }
                    for(int k=97; k<=122; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-97];
                        }
                    }
                }
                length=s1.length();
                for(int j=0; j<length; j++)
                {
                    char_s=s[j];
                    value=(int)char_s;
                    for(int k=65; k<=90; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-65];
                        }
                    }
                    for(int k=97; k<=122; k++)
                    {
                        if(value==k)
                        {
                            score=score+alp[k-97];
                        }
                    }
                }
                if(check(s) && check (s1))
                cout<<"English String = "<<original_s1<<endl;
                else
                cout<<"Not English String = "<<original_s1<<" With Score = "<<score<<endl;
            }
        }
    }   
}

string encode_keyword(string original_s, string keyword)
{
    char char_s;
    int length_s=original_s.length(),length_k=keyword.length(),k=0,f=0,j=0,value;
    for(int i=0; i<length_s; i++)
    {
        value=(int)original_s[i];
        keyword[f]=toupper(keyword[f]);
        if(value>=65 && value<=90)
        {
            original_s[i]=encode_char(original_s[i],(keyword[f]-64));
            f++;
        }
        else if(value>=97 && value<=122)
        {
            original_s[i]=encode_char(original_s[i],(keyword[f]-64));
            f++;
        }
        if(f==(length_k))
        f=0;       
    }
    return original_s;    
}

string decode_keyword(string original_s, string keyword)
{
    char char_s;
    int length_s=original_s.length(),length_k=keyword.length(),k=0,f=0,j=0,value;
    for(int i=0; i<length_s; i++)
    {
        value=(int)original_s[i];
        keyword[f]=toupper(keyword[f]);
        if(value>=65 && value<=90)
        {
            original_s[i]=decode_char(original_s[i],(keyword[f]-64));
            f++;
        }
        else if(value>=97 && value<=122)
        {
            original_s[i]=decode_char(original_s[i],(keyword[f]-64));
            f++;
        }
        if(f==(length_k))
        f=0;       
    }
    return original_s;    
}

int main()
{
    loadDictionary("english3.txt");
    int n=0,shift_value;
    string s,keyword;
    while(n!=6)
    {
        cout<<"1. decode an encoded cipher using shift value"<<endl;;
        cout<<"2. encode a cipher using shift value"<<endl;
        cout<<"3. decode an encoded cipher without using shift value"<<endl;
        cout<<"4. decode an encoded cipher using keyword"<<endl;
        cout<<"5. encode a cipher using keyword"<<endl;
        cout<<"6. exit"<<endl;
        cin>>n;
        if(n==1)
            {
                cout<<"Enter string and shift value"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            cin>>shift_value;
            cout<<decode(s,shift_value)<<endl;
            }
            else if(n==2)
            {cout<<"Enter string and shift value"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            cin>>shift_value;
            cout<<encode(s,shift_value)<<endl;
            }
            else if(n==3)
            {cout<<"Enter string"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            decode_new(s);
            }
            else if(n==4)
            {cout<<"Enter string and keyword"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            cin>>keyword;
            cout<<decode_keyword(s,keyword)<<endl;}
            else if(n==5)
            {cout<<"Enter string and keyword"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,s);
            cin>>keyword;
            cout<<encode_keyword(s,keyword)<<endl;
            }
        }
}