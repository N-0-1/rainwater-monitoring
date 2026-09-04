-- phpMyAdmin SQL Dump
-- version 5.2.3
-- https://www.phpmyadmin.net/
--
-- Host: mariaDB
-- Gegenereerd op: 27 aug 2026 om 10:37
-- Serverversie: 11.4.8-MariaDB-log
-- PHP-versie: 8.4.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `raintankNetwork`
--

-- --------------------------------------------------------

--
-- Tabelstructuur voor tabel `device`
--

CREATE TABLE `device` (
  `id` int(10) UNSIGNED NOT NULL,
  `device_id` char(16) NOT NULL,
  `device_eui` char(16) NOT NULL,
  `location` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Tabelstructuur voor tabel `measurement`
--

CREATE TABLE `measurement` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `device_id` int(10) UNSIGNED NOT NULL,
  `uplink_at` datetime NOT NULL,
  `battery_voltage_cv` decimal(8,3) UNSIGNED DEFAULT NULL,
  `flow_volume_ml` decimal(12,3) UNSIGNED DEFAULT NULL,
  `level_cm` decimal(12,3) UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Tabelstructuur voor tabel `radio_metadata`
--

CREATE TABLE `radio_metadata` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `measurement_id` bigint(20) UNSIGNED NOT NULL,
  `gateway_name` varchar(100) NOT NULL,
  `gateway_eui` char(16) NOT NULL,
  `rssi` int(11) DEFAULT NULL,
  `snr` decimal(5,2) DEFAULT NULL,
  `latitude` decimal(10,7) DEFAULT NULL,
  `longitude` decimal(10,7) DEFAULT NULL,
  `height` decimal(8,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexen voor geëxporteerde tabellen
--

--
-- Indexen voor tabel `device`
--
ALTER TABLE `device`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `uq_device_eui` (`device_eui`);

--
-- Indexen voor tabel `measurement`
--
ALTER TABLE `measurement`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idx_measurement_device` (`device_id`),
  ADD KEY `idx_measurement_device_time` (`device_id`,`uplink_at`),
  ADD KEY `idx_measurement_time` (`uplink_at`);

--
-- Indexen voor tabel `radio_metadata`
--
ALTER TABLE `radio_metadata`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idx_radio_metadata_measurement` (`measurement_id`),
  ADD KEY `idx_radio_metadata_gateway` (`gateway_eui`);

--
-- AUTO_INCREMENT voor geëxporteerde tabellen
--

--
-- AUTO_INCREMENT voor een tabel `device`
--
ALTER TABLE `device`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT voor een tabel `measurement`
--
ALTER TABLE `measurement`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT voor een tabel `radio_metadata`
--
ALTER TABLE `radio_metadata`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- Beperkingen voor geëxporteerde tabellen
--

--
-- Beperkingen voor tabel `measurement`
--
ALTER TABLE `measurement`
  ADD CONSTRAINT `measurement_ibfk_1` FOREIGN KEY (`device_id`) REFERENCES `device` (`id`) ON DELETE CASCADE;

--
-- Beperkingen voor tabel `radio_metadata`
--
ALTER TABLE `radio_metadata`
  ADD CONSTRAINT `fk_radio_metadata_measurement` FOREIGN KEY (`measurement_id`) REFERENCES `measurement` (`id`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
