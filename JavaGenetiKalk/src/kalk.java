import Monomero.*;
import Polimero.*;

import java.util.ArrayList;

public class kalk
{
    public static void main(String args[]){

        ArrayList<nucleotide> nuc = new ArrayList<nucleotide>();

        DNA seq= new DNA(nuc , false, null);
        seq.addEle(genCode.dnaA);
        seq.addEle(genCode.dnaC);
        seq.addEle(genCode.dnaT);
        seq.addEle(genCode.dnaG);
        seq.addEle(genCode.dnaA);
        seq.addEle(genCode.dnaG);

        double m = seq.calcMass();
        System.out.print("Massa DNA: " + m);

        System.out.println("");

        System.out.print("Metodo delEle su DNA:");
        seq.delEle();
        for(Object i : seq.getElems())
            System.out.print(((nucleotide)i).getAcr());

        System.out.println("");

        System.out.print("Calcolo sequenza Complementare:");
        seq.calcSeqComp();
        for(Object i : seq.getseqDNA().getElems())
            System.out.print(((nucleotide)i).getAcr());

        System.out.println("");

        ArrayList<nucleotide> al = new ArrayList<nucleotide>();

        RNA seqRNA= new RNA(al, true);
        seqRNA= seq.toRNA();

        System.out.print("DNA to RNA: ");
        for(Object i : seqRNA.getElems())
            System.out.print(((nucleotide)i).getAcr());

        ArrayList<nucleotide> n = new ArrayList<nucleotide>();
        RNA concatRNA= new RNA(n, true);

        concatRNA.addEle(genCode.rnaA);
        concatRNA.addEle(genCode.rnaG);
        concatRNA.addEle(genCode.rnaU);
        concatRNA.addEle(genCode.rnaG);

        seqRNA=seqRNA.concat(concatRNA);

        System.out.println("");

        System.out.print("Concatenazione di due RNA: ");
        for(Object i : seqRNA.getElems())
            System.out.print(((nucleotide)i).getAcr());

        System.out.println("");
        System.out.print("Conversione da RNA a DNA:");

        seq= seqRNA.toDNA();

        for(Object i : seq.getElems())
            System.out.print(((nucleotide)i).getAcr());

        seqRNA.splicing(3, 5);

        System.out.println("");

        System.out.println("Splicing:");

        for(Object i : seqRNA.getElems())
            System.out.print(((nucleotide)i).getAcr());

        System.out.println("");
        System.out.println("Da RNA a Proteina:");

        ArrayList<Amminoacido> a = new ArrayList<Amminoacido>();
        Proteina seqProt=new Proteina(a, 0.0);
        seqProt=seqRNA.toProteina();



        for(Object i : seqProt.getElems())
            System.out.print(((Amminoacido)i).getAcr());
        System.out.println("");

        seqProt.addElem(genCode.ammAla);
        seqProt.addElem(genCode.ammAsp);
        seqProt.addElem(genCode.ammAsp);

        seqProt=seqProt.concat(seqProt);

        System.out.print("Concatenazione di due proteine: ");
        for(Object i : seqProt.getElems())
            System.out.print(((Amminoacido)i).getAcr());

        System.out.println("");

        double volume=seqProt.calcVol();
        System.out.print("Volume delle proteine: " + volume);

        System.out.println("");

        Proteina seqPro = new Proteina(a, 0.0);

        seqProt.addElem(genCode.ammAla);
        seqProt.addElem(genCode.ammAsp);
        seqProt.addElem(genCode.ammAsp);

        boolean b= seqPro.isSimilar(seqProt);
        System.out.println("Invocazione della funzione isSimilar in proteina");

        if(b==true)
            System.out.print("Le due sequenze sono simili");
        else
            System.out.print("Le due sequenze sono diverse");
    }
}
