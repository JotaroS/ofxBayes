# ofxBayes
![thumbnail](thumbnail.png)

## Introduction
ofxBayes is openFrameworks addon for Bayesian statistics. Now this is a baby project.
Currently, you can

- Add your own hypothesis and probability as `map<int, int>` 
- Write your own likelihood function by giving lambda pointer function.

for detail take a look at codes below.

## Dependency
currently none.

## Example


### example-basic
Simple Monty-hall problem.
Three steps required.

1. Make prior probability
2. Write likelihood function
3. Update your guess!

```[cpp]

    //Hypothesis and data
    _map[0] = 0.f;
    _map[1] = 0.f;
    _map[2] = 0.f;

    //initialization
    ofxBayesHist hist(_map);
    hist.initialize(); 
    hist.disp("Prior probability");

    //Likelihood function
    int choise = 0;
    hist.likelihoodFunc = [=](int data, int hypo) { 

        if (hypo == data)
            return 0.f; //monty cannot open the door if there's A8.
        else
        {
            if (hypo == choise)
                return 0.5f; //if you choose the door which there's A8, Monty can open the rest of the door at the same prob.
            else
                return 1.f; //Monty has no choise but open the door.
        }
    };

    //update posterior prob.
    hist.update(1);
    hist.disp("Posterior probability");
```


## License
MIT