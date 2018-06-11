#include "gen_costants.h"

const QString gencode::massUnit = "u";

const QVector<Nucleotide> gencode::dnaCode = {Nucleotide("Adenosina", "A", 331.2, false, "T"),
                                              Nucleotide("Citidina", "C", 307.2, false,"G"),
                                              Nucleotide("Guanosina", "G", 347.2, false, "C"),
                                              Nucleotide("Timidina", "T", 322.2, false,"A")};


const QVector<Nucleotide> gencode::rnaCode = {Nucleotide("Adenosina", "A", 347.2, true, "T"),
                                              Nucleotide("Citidina", "C", 323.2, true,"G"),
                                              Nucleotide("Guanosina", "G", 363.2, true, "C"),
                                              Nucleotide("Uridina", "U", 324.2, true,"A")};

const QVector<Amminoacido> gencode::proCode = {Amminoacido("Alanina", "Ala", 89.09, {"GCU", "GCC", "GCA", "GCG"}),
                                               Amminoacido("Arginina", "Arg", 1, {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG"}),
                                               Amminoacido("Asparagina", "Asn", 132.12, {"AAU" "AAC"}),
                                               Amminoacido("Acido aspartico", "Asp", 133.10, {"GAU","GAC"}),
                                               Amminoacido("Cisteina", "Cys", 121.16, {"UGU","UGC"}),
                                               Amminoacido("Glutammina", "Gln", 146.15, {"CAA","CAG"}),
                                               Amminoacido("Acido glutammico", "Glu", 147.13, {"GAA","GAG"}),
                                               Amminoacido("Glicina", "Gly", 75.07, {"GGU","GGC", "GGA", "GGG"}),
                                               Amminoacido("Istidina", "His", 155.16, {"CAU", "CAC"}),
                                               Amminoacido("Isoleucina", "Ile", 131.18, {"AUU", "AUC", "AUA"}),
                                               Amminoacido("Leucina", "Leu", 131.18, {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG"}),
                                               Amminoacido("Lisina", "Lys", 146.19, {"AAA", "AAG"}),
                                               Amminoacido("Metionina", "Met", 149.21, {"AUG"}),
                                               Amminoacido("Fenilalanina", "Phe", 165.19, {"UUU", "UUC"}),
                                               Amminoacido("Prolina", "Pro", 115.13, {"CCU", "CCC", "CCA", "CCG"}),
                                               Amminoacido("Serina", "Ser", 105.09, {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"}),
                                               Amminoacido("Treonina", "Thr", 119.12, {"ACU", "ACC", "ACA", "ACG"}),
                                               Amminoacido("Triptofano", "Trp", 204.23, {"UGG"}),
                                               Amminoacido("Tirosina", "Tyr", 181.19, {"UAU", "UAC"}),
                                               Amminoacido("Valina", "Val", 117.15, {"GUU", "GUC", "GUA", "GUG"}),
                                               Amminoacido("STOP", "STOP", 0, {"UAA", "UAG", "UGA"})};
