setwd("/home/avinash/Desktop/wineproject/projectfiles")
white<-read.csv(file = "winequality-white.csv",head=TRUE, sep=";")
red<-read.csv(file = "winequality-red.csv",head=TRUE, sep=";")
white$cat<-"white"
red$cat<-"red"
newdata<-rbind(red,white)
head(newdata)
summary(newdata)
k<-sample(x = 2, size = nrow(newdata), replace = TRUE, prob = c(0.30,0.70))
test.cases<-newdata[k==2,]
training.cases<-newdata[k==1,]
table(newdata$cat)/nrow(newdata)
library(rpart)
library(rpart.plot)
temp<-test.cases[1500,]
print(temp)
fitcTree<-rpart(data = training.cases,method = "class", formula =  cat~fixed.acidity+volatile.acidity+citric.acid+total.sulfur.dioxide+chlorides+alcohol+density)
predcTree<-predict(fitcTree,newdata=temp,type="class")
rpart.plot(fitcTree)
fitqTree<-rpart(data = training.cases,method = "anova", formula =  quality~fixed.acidity+volatile.acidity+citric.acid+total.sulfur.dioxide+chlorides+alcohol+density)
predrTree<-predict(fitqTree,newdata=temp,type="vector")
rpart.plot(fitqTree)
library(caret)
help("confusionMatrix")
print(predcTree)
confusionMatrix(predcTree,temp$cat)
