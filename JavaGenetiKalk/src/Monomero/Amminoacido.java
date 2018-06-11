package Monomero;

import java.util.ArrayList;
import java.lang.String;
import Polimero.*;


public class Amminoacido extends Monomero{
    private ArrayList<String> _codon; //codoni associati

    public Amminoacido(String n, String a, double m, ArrayList<String> codon){
        super(n, a, m);
        _codon=codon;
    }

    ArrayList<String> getCodon(){
        return _codon;
    }

    void setCodon(ArrayList<String> c) {
        _codon=c;
    }

    double calcPercentage(Polimero p){
        int count=0;
        for(Object i : p.getElems()){
            if(i.equals(this))
                count++;
        }
        return ((count*100)/p.getLength());
    }


    public int findInSequence(ArrayList<nucleotide> n){
        if(n.size()>0){
            for(int i = 0; i < n.size(); i+=3){
                String temp= new String();
                temp.concat(n.get(i).getAcr());
                if((i+1)<n.size())
                    temp.concat(n.get(i+1).getAcr());
                if((i+2)<n.size())
                    temp.concat(n.get(i+2).getAcr());

                for(Object j : getCodon())
                    if(temp.equals(j))
                        return (i + 1);
            }
            return 0;
        }
        return -1;
    }

}
