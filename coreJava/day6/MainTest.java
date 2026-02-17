package day6;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import day6.classes.City;
import day6.classes.Country;

public class MainTest {

    public static void main(String[] args) {
        List<Country> countriesList = new ArrayList<>();
        List<City> citiesList = new ArrayList<>();

        // reading countries
        try (BufferedReader br = new BufferedReader(new FileReader("day6/Countries.csv"))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                if (values.length < 7)
                    continue;
                countriesList.add(new Country(
                        values[0].trim(),
                        values[1].trim(),
                        values[2].trim(),
                        Double.parseDouble(values[3].trim()),
                        (int) Double.parseDouble(values[4].trim()),
                        Double.parseDouble(values[5].trim()),
                        (int) Double.parseDouble(values[6].trim())));
            }
        } catch (

        IOException e) {
            System.out.println("country list error" + e);
        }

        // reading cities
        try (BufferedReader br = new BufferedReader(new FileReader("day6/Cities.csv"))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] values = line.split(",");
                if (values.length < 4)
                    continue;
                citiesList.add(new City(
                        (int) Double.parseDouble(values[0].trim()),
                        values[1].trim(),
                        (int) Double.parseDouble(values[2].trim()),
                        values[3].trim()));
            }
        } catch (

        IOException e) {
            System.out.println("city list error" + e);
        }

        // Find the highest populated city of each country
        System.out.println("==========Find the highest populated city of each country============");
        List<City> maxCities = countriesList.stream()
                .map(country -> citiesList.stream()
                        .filter(city -> city.getCountryCode().equals(country.getCode()))
                        .max(Comparator.comparingInt(City::getPopulation))
                        .orElse(null))
                .collect(Collectors.toList());

        maxCities.forEach(c -> {
            if (c != null)
                System.out.println(c.getName() + ", " + c.getCountryCode());
        });

        // Find the most populated country of each continent
        System.out.println("==========Find the most populated country of each continent============");
        List<Country> maxCountry = countriesList.stream()
                .map(e -> e.getContinent())
                .distinct()
                .map(continent -> countriesList.stream().filter(country -> country.getContinent().equals(continent))
                        .max(
                                Comparator.comparingInt(Country::getPopulation))
                        .orElse(null))
                .collect(Collectors.toList());

        maxCountry.forEach(c -> {
            if (c != null)
                System.out.println("country: " + c.getName() + "\ncontinent: " + c.getContinent() + "\npopulation: "
                        + c.getPopulation());
        });

        System.out.println("==========Find the highest populated capital city============");
        // Find the highest populated capital city

        City maxCapital = countriesList.stream()
                .map(Country::getCapital)
                .flatMap(capitalId -> citiesList.stream()
                        .filter(c -> c.getId() == capitalId))
                .max(Comparator.comparingInt(City::getPopulation))
                .orElse(null);

        System.out.println(maxCapital);
    }
}
