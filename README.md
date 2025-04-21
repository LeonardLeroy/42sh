# 42sh

## Chère équipe,
Dans le cadre du projet 42sh, nous devons structurer notre travail de manière efficace afin d’assurer une progression fluide et respecter les délais. Voici l’organisation prévue :

### 📌 Répartition des tâches

- Gestion du Parsing : 
    - Léonard LEROY → Implémentation des fonctionnalités d’inhibition → implémentation des backticks (‘`’)
    - Valentin GUINET → Implémentation des parenthèses (‘(‘  ‘)’)
- Gestion de l'exécution :
    - Pierre RISS → Implémentation des fonctionnalités d’englobbage (‘*’, ‘?’ et ‘[‘ ‘]’) → Implémentation du scripting
    - Sacha HENNEVEUX → Implémentation de la séparation de processus
- Gestion des variables :
    - Evan LAFOLIE → Implémentation des variables locales, d’environnements et spéciales → Implémentation des alias
    - Sacha HENNEVEUX → Implémentation du echo $
- Gestion d’historique :
    - Valentin GUINET → Implémentation de l’historique, du build-in “history” → Implémentation de l’auto complétion avec “tab” ou avec le point d’exclamation

### 🗓 Planning & Deadlines

- Sprint actuel : 05 april – 11 april, Rendu final prévu pour le 9 mai
- Prochaine réunion : 11 april – Point d’avancement et ajustements, inscrivons à l’ordre du jour l’ajout potentiel de l’outil copilot à notre projet

### 🔗 Méthodologie & Outils
Outils : GitHub (gestion du code, une branche par personne), Trello (suivi des tâches)

Votre implication est essentielle pour le succès de ce projet. N’hésitez pas à me contacter pour toute question.
Restons synchronisés et motivés !

Valentin GUINET
Chef de projet IT

## Léo

- [ ] inhibitors `\`
- [ ] backticks

## Loray

- [ ] variables
    - [ ] local
    - [x] env
- [ ] special variables
    - [ ] term
    - [ ] precmd
    - [ ] cwdcmd
    - [ ] cwd
    - [ ] ignoreof for instance
- [ ] aliases
- memory leak

## Sacha

- [ ] job control
    - [ ] `&`
    - [ ] `fg`
    - [ ] `bg`

## Pierre

- [ ] globbings
    - [ ] `*`
    - [ ] `?`
    - [ ] `[` et `]`
- [ ] scripting

## Val

- [x] parentheses `(`, `)`
- [ ] history
    - [x] history
    - [ ] `!`
- [ ] line edition
    - [ ] multiline
    - [x] dynamic rebinding
    - [ ] auto-completion dynamic