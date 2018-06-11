package Polimero;

import Monomero.*;
import java.util.ArrayList;

public class DNA extends Polimero{
    private boolean _isSense;
    private DNA _seqDNA;

    public DNA(ArrayList<nucleotide> n, boolean b, DNA seq) {
        super(n);
        _isSense=b;
        _seqDNA=seq;
    }

    public boolean getIsSense(){
        return _isSense;
    }

    public DNA getseqDNA(){
        return _seqDNA;
    }

    public void setIsSense(boolean isSense){
        _isSense=isSense;
    }

    public void setseqDNA(DNA seqDNA){
        _seqDNA=seqDNA;
    }

    public double calcMass(){
        double mass =0;

            for (Object i : getElems())
                mass += ((nucleotide) i).getMass();
            if(getseqDNA() != null ) {
                if (getseqDNA().getElems().size() > 0) {
                    for (Object j : getseqDNA().getElems())
                        mass += ((nucleotide) j).getMass();
                }
            }
        return mass;
    }

    public boolean validate(nucleotide n){
        //manca l'oggetto creato con gli elementi di codiceRNA
        boolean b=false;
        for(Object i : genCode.dnaCode) {
            if ( i.equals(n))
                b = true;
        }
        return b;
    }

    public void calcSeqComp(){
        ArrayList<nucleotide> _elemsComp=new ArrayList<nucleotide>();

        for(Object i : getElems())
            for (Object j : genCode.dnaCode)
                if((((nucleotide)i).getComp()).equals(((nucleotide)j).getAcr()))
                    _elemsComp.add((nucleotide)j);
        setseqDNA(new DNA(_elemsComp, !getIsSense(), this));
    }

    public RNA toRNA(){
        ArrayList<nucleotide> _toRNAElems= new ArrayList<nucleotide>();
        for(Object i : getElems())
            for(Object j : genCode.rnaCode){
                if ((((nucleotide) i).getAcr()).equals(((nucleotide)j).getComp()))
                    _toRNAElems.add((nucleotide)j);
        }
            return new RNA(_toRNAElems, !_isSense);
    }

    public void addEle(nucleotide n){
        ArrayList<nucleotide> newArr = getElems();

        newArr.add(n);
        if(_seqDNA != null)
            calcSeqComp();
        updateInfo();
    }

    public void delEle(){
        ArrayList<nucleotide> newVec = getElems();
        newVec.remove(newVec.size()-1);
        setElem(newVec);
        updateInfo();
    }

    public DNA concat(IPolimero i){
        ArrayList<nucleotide> newNuc= new ArrayList<nucleotide>();
        DNA d=new DNA(null, false, null);

        if(d instanceof DNA)
            d=(DNA)i;

        for(Object x : getElems())
            newNuc.add((nucleotide)x);
        for(Object j : d.getElems())
            newNuc.add((nucleotide)j);

        return new DNA(newNuc, false, null);

    }

    public DNA toSeqComp(){
        return getseqDNA();
    }

}
