# strcnv
<p>
    <br>library that allows to get a string and convert it to int, long, float or double
</p>
<p>
    <br>
    <br>for use it just call one of this function:
    <br>
</p>
<p>
    <br>int lint(string)        \\function to get a string on standard input and translate to int
    <br>long llong(string)      \\function to get a string on standard input and translate to long
    <br>float lfloat(string)    \\function to get a string on standard input and translate to float
    <br>double lfloat(string)   \\function to get a string on standard input and translate to double
    <br>
</p>
<p>
    <br>if you want to use the function for translation directly u can use this funcion
    <br>double valc(string,short) \\return a double and need a string for translation and one short that indicate the type of translation:
        <ol>
            <li>int</li>
            <li>long</li>
            <li>float</li>
            <li>double</li>
        </ol>
</p>
<p>
    <br>New Funntions: 
    <ul>
        <li>void sminusc(char str[])                          //convert uppercase to lowercase</li>
        <li>void smaiusc(char str[])                          //convert lowercase to uppercase</li>
        <li>short cerca(char sdt[],char in[])                 //Seecking sdt [] in the string in[] and return 0 for different strings, 1 for identical strings, 2 if sdt is contained entirely (in the right order) in string in [], 3 if one or more characters are contained</li>
        <li>void copia_riga(char out[],char str[])</li>       //copy str in out removing '\0' and '\n'
        <li>void strunion(char str1[],char str2[],char c_end) //It combines two strings ant put the character c_end to the middle and the end</li>
        <li>void split(char out[],char inp[],char del)        //return in out[] all characters of inp till it find "del" character</li>
    </ul>
</p>
